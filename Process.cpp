#include "Process.h"
/*
The Process class does much of the heavy lifting for this algorithm. Given a 
MuBlock containing samples, the Process class will do fourier, cepstral, and/or
warped cepstral coefficient calculations.

Any data structures allocated here are (or should be) freed by the MuBlock
destructor.
*/

//Use FFTW to perform a bunch of i64_fftlen FFTs, without zero padding.
void Process::FFTW(MuBlock* in, int64_t i64_fftlen) {
    in->fft.i64_fftlen = i64_fftlen;
    //i64_fftnum is how many will fit in the total number of samples 
    in->fft.i64_fftnum = (int64_t)((float)in->wav.i64_wavlen/in->fft.i64_fftlen);
    size_t total_size = sizeof(std::complex<double>)*in->fft.i64_fftlen*in->fft.i64_fftnum;
    in->fft.p_cpd_fftdata = (std::complex<double> *)fftw_malloc(total_size);

    //Example usage of fftw_plan_many_dft can be found at kkjkok.blogspot.com
    //  Looking th FFTW documentation for what each field should contain
    //  may also help.
    fftw_plan plan = fftw_plan_many_dft( 1,
                                         (int *)&in->fft.i64_fftlen,
                                         in->fft.i64_fftnum,
                                         (fftw_complex *)in->fft.p_cpd_fftdata,
                                         NULL,
                                         in->fft.i64_fftnum,
                                         1, 
                                         (fftw_complex *)in->fft.p_cpd_fftdata,
                                         NULL,
                                         in->fft.i64_fftnum,
                                         1,
                                         FFTW_FORWARD,
                                         FFTW_ESTIMATE );

    //Copy data into the allocated FFT array, applying window values contained
    //in Window.h. Current window is Blackman-Harris
    for (size_t i=0; i<(in->fft.i64_fftnum*in->fft.i64_fftlen); i++) {
        in->fft.p_cpd_fftdata[i].real(in->wav.p_s_wavdata[i]*window[i%in->fft.i64_fftlen]);
        in->fft.p_cpd_fftdata[i].imag(0);
    }
    
    fftw_execute(plan);

    //Also populate PSD array for easy viewing of signal power.
    in->fft.p_d_psd = new double[in->fft.i64_fftnum*in->fft.i64_fftlen];
    for (size_t i=0; i<(in->fft.i64_fftnum*in->fft.i64_fftlen); i++) {
        in->fft.p_d_psd[i] = log10(std::norm(in->fft.p_cpd_fftdata[i]));
    }
    fftw_destroy_plan(plan);
}

//Take PSD values, the perform an FFT to get cepstrum. Comments from above about
//  how to use fftw_plan_many_dft apply again here.
void Process::CepstrumFFTW(MuBlock* in, int64_t i64_ceplen) {
    in->cep.i64_ceplen = i64_ceplen;
    in->cep.i64_cepnum = (int64_t)((float)in->fft.i64_fftlen*in->fft.i64_fftnum/in->cep.i64_ceplen);
    size_t total_size = sizeof(std::complex<double>)*in->cep.i64_ceplen*in->cep.i64_cepnum;
    in->cep.p_cpd_cepdata = (std::complex<double> *)fftw_malloc(total_size);
    fftw_plan plan = fftw_plan_many_dft( 1,
                                         (int *)&in->cep.i64_ceplen,
                                         in->cep.i64_cepnum,
                                         (fftw_complex *)in->cep.p_cpd_cepdata,
                                         NULL,
                                         in->cep.i64_cepnum,
                                         1, 
                                         (fftw_complex *)in->cep.p_cpd_cepdata,
                                         NULL,
                                         in->cep.i64_cepnum,
                                         1,
                                         FFTW_FORWARD,
                                         FFTW_ESTIMATE );
    
    //Copy in the data - might look at changing the dft to non-overwrite type
    //  eventually, but this works ok for now.    
    for (size_t i=0; i<(in->cep.i64_cepnum*in->cep.i64_ceplen); i++) {
        in->cep.p_cpd_cepdata[i].real(in->fft.p_d_psd[i]);
        in->cep.p_cpd_cepdata[i].imag(0);
    }

    fftw_execute(plan);
    fftw_destroy_plan(plan);
}

//Take in MuBlock with FFT and PSD data, then perform a 2D dct to cepstral coeff
//  values. Look up Mel Frequency Cepstral Coefficients, or Bark Frequency
//  Cepsral Coefficients. Current implementation is Bark.
void Process::DCTFFTW(MuBlock* in) {

    //Figure out edge of every Bark filter, and also truncate so that we do not
    //  attempt to access frequency bins > fs/2 (generally fs/2 will be 22050) 
    std::vector<int64_t> stopbins;
    int64_t temp;
    for (size_t i=0; i<COEFFS; i++) {
        temp = (int64_t)(stops[i]*((float)in->fft.i64_fftlen)/in->wav.i64_samplerate);
        if (temp < in->fft.i64_fftlen/2) {
            stopbins.push_back(temp);
            //Uncomment this line to see Bark stops
            //printf("%ld\n", temp);
        }
    }

    in->bfcc.i64_bfcclen = (int64_t)stopbins.size();
    in->bfcc.i64_bfccnum = in->fft.i64_fftnum;
    in->bfcc.p_d_bfccdata = new double[in->bfcc.i64_bfcclen*in->bfcc.i64_bfccnum];
    //Zero out memory so we only need to populate barkcenter values.
    memset(in->bfcc.p_d_bfccdata, 0, sizeof(double)*in->bfcc.i64_bfcclen*in->bfcc.i64_bfccnum); 
    
    //Step through the array, computing a weighted sum of the PSD in each
    //  bark filter. This sum will be placed at the bark center frequency. 
    //  See ../References/musicir_paper.pdf, pg. 5, or 
    //  Spectral Sudio Signal Processing, Appendix E: Bilinear Frequency Warping
    for (size_t i=0; i<(size_t)in->bfcc.i64_bfccnum; i++) { 
        for (size_t j=2; j<(size_t)in->bfcc.i64_bfcclen; j++) {
            //Accumulator for this filter
            long double accum = 0; 

            //Size of the filter being computed
            int64_t filtlen = stopbins[j]-stopbins[j-2];

            for (size_t k=(size_t)stopbins[j-2]; k<(size_t)stopbins[j]; k++) {
                double triangle_step = 1/(double)filtlen;
                double mult = 1;
                //Apply a triangle weight with maximum value of .5
                //  Should be like [.1, .2, .3, .4, .5, .4, .3, .2, .1]
                if ((k-stopbins[j-2])<(size_t)filtlen/2) {
                    mult = (k-stopbins[j-2])*triangle_step;
                } else {
                    mult = 1-((k-stopbins[j-2])*triangle_step);
                }
                //Add value to accumulator for the current filter
                accum += in->fft.p_d_psd[k]*mult;
            }
            //Set value at the filter center frequency to accum
            in->bfcc.p_d_bfccdata[i*in->bfcc.i64_bfcclen+(j-2)] = accum; 
        }
    }
   
    //Perform 2D DCT-II transform on warp filtered data  
    fftw_r2r_kind fftkind = FFTW_REDFT10;
    fftw_r2r_kind fftkind2 = FFTW_REDFT10; 
    fftw_plan plan = fftw_plan_r2r_2d( in->bfcc.i64_bfcclen,
                                       in->bfcc.i64_bfccnum,
                                       in->bfcc.p_d_bfccdata,
                                       in->bfcc.p_d_bfccdata,
                                       fftkind, 
                                       fftkind2, 
                                       FFTW_ESTIMATE );
    
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}
Process::Process() {
}
Process::~Process() {
}

//Interface to perform BFCC. Used so that processing can be moved to GPU without
//  changing calling code.
void Process::BFCC(MuBlock* in, int64_t i64_fftlen, int64_t i64_ceplen) {
   if (in->fft.p_cpd_fftdata == NULL) {
       this->FFTW(in, i64_fftlen);
   }
   //this->CepstrumFFTW(in, i64_ceplen); 
   this->DCTFFTW(in);
}

//Interface to FFT, same reasoning as BFCC.
void Process::FFT(MuBlock* in, int64_t i64_fftlen) {
    if (in->fft.p_cpd_fftdata == NULL) {
        this->FFTW(in, i64_fftlen);
    }
} 
