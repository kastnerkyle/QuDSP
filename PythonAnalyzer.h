#ifndef _PYTHON_ANALYZER_H_
#define _PYTHON_ANALYZER_H_

#include <python2.7/Python.h>
#include <arrayobject.h>
#include "MuBlock.h"

class PythonAnalyzer {
    private:
        MuBlock* mp_data;
        PyObject* mp_python_f;
        void setFileInfo(MuBlock* data);
        void setWAVInfo(wavinfo wav);
        void setFFTInfo(fftinfo fft);
        void setCepstrumInfo(cepinfo cep);
        void setBFCCInfo(bfccinfo bfcc);
        void setPythonMuBlockData(MuBlock* data);
    public:
        PythonAnalyzer(MuBlock* data);
        ~PythonAnalyzer();
        std::string Run(std::string python_f);
};
#endif
