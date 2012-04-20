#include <mpg123.h>
#include "MuBlock.h"
/*
The MuBlock class is a glorified struct, for holding time series, frequency,
cepstral, and scale warped cepstral coefficients. Memory for stored data is 
allocated in the function that does the transform (DataCollector, Process, etc.)
but is ALWAYS freed in the deconstructor here. If new data catagories are added
they should follow this trend.

The MuBlock should live until the end of the program, as it represents all 
current knowledge about the contents of a file.
*/

//Constructor initializes to a known starting state.
MuBlock::MuBlock() {
    fft.p_cpd_fftdata = NULL;
    fft.p_d_psd = NULL;
    fft.i64_fftlen = 0;
    fft.i64_fftnum = 0;
    
    cep.p_cpd_cepdata = NULL;
    cep.i64_ceplen = 0;
    cep.i64_cepnum = 0;
    
    wav.p_s_wavdata = NULL;
    wav.i64_wavlen = 0;
    wav.n_channels = 0;
    wav.i64_samplerate = 0;

    bfcc.p_d_bfccdata = NULL;
    bfcc.i64_bfcclen = 0;
    bfcc.i64_bfccnum = 0;
}

//If data has been allocated during the run of the program, free it.
MuBlock::~MuBlock() {
    if ( fft.p_cpd_fftdata != NULL ) {
        fftw_free(fft.p_cpd_fftdata);
    }
    if (fft.p_d_psd != NULL) {
        delete [] fft.p_d_psd;
    }
    if (cep.p_cpd_cepdata != NULL) {
        fftw_free(cep.p_cpd_cepdata);
    }
    if ( wav.p_s_wavdata != NULL ) {
        delete [] wav.p_s_wavdata;
    }
    if (bfcc.p_d_bfccdata != NULL ) {
        delete [] bfcc.p_d_bfccdata;
    }
}
