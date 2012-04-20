#ifndef _MUBLOCK_H_
#define _MUBLOCK_H_

#include <complex>
#include <fftw3.h>
#include <cstddef>
#include <iostream>
#include <fstream>

struct fftinfo {
    std::complex<double>* p_cpd_fftdata;
    double* p_d_psd;
    int64_t i64_fftlen;
    int64_t i64_fftnum;
};
struct cepinfo {
    std::complex<double>* p_cpd_cepdata;
    int64_t i64_ceplen;
    int64_t i64_cepnum;
};
struct wavinfo {
    short* p_s_wavdata;
    int64_t i64_wavlen;
    int n_channels;
    int64_t i64_samplerate;
};
struct bfccinfo {
    int64_t i64_bfcclen;
    int64_t i64_bfccnum;
    double* p_d_bfccdata;
};

class MuBlock {
    public:
        std::string name;
        std::ofstream f_wav;
        std::ofstream f_fft;
        fftinfo fft;
        cepinfo cep;
        wavinfo wav;
        bfccinfo bfcc;
        MuBlock();
        ~MuBlock();
};
#endif
