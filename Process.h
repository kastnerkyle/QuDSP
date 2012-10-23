#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <complex>
#include <fftw3.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <Eigen/Core>
#include "MuBlock.h"
#include "Window.h"

//COEFFS and stops define the stop frequencies for a Bark frequency filter
#define COEFFS 26
static const int64_t stops[COEFFS] = {
0,
100,
200,
400,
510,
630,
770,
920,
1080,
1270,
1480,
1720,
2000,
2320,
2700,
3150,
3700,
4400,
5300,
6400,
7700,
9500,
12000,
15500,
20500,
27000}; 

class Process {
    private:
        void FFTW(MuBlock* in, int64_t i64_fftlen);
        void CepstrumFFTW(MuBlock* in, int64_t i64_ceplen);
        void DCTFFTW(MuBlock* in);
    public:
        Process();
        ~Process();
        void FFT(MuBlock* in, int64_t i64_fftlen);
        void BFCC(MuBlock* in, int64_t fftlen, int64_t i64_ceplen);
};
#endif
