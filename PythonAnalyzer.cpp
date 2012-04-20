#include "PythonAnalyzer.h"
/*
The PythonAnalyzer class makes the data from a MuBlock accessible to python
scripts. No data copying due to the awesomeness that is PyArray (thanks NumPy!)
*/

//songpath variable in python holds entire path to file being processed.
void PythonAnalyzer::setFileInfo(MuBlock* data) {
    PyObject* py_m = PyImport_AddModule("__main__");
    PyModule_AddObject(py_m, "songpath", Py_BuildValue("s", &data->name[0]));
}

//All data associated with MuBlock.wav struct exposed here
void PythonAnalyzer::setWAVInfo(wavinfo wav) {
    npy_intp dims[1] = {wav.i64_wavlen};
    PyObject* py_wavdata = PyArray_SimpleNewFromData(1,
                                                     dims,
                                                     NPY_INT,
                                                     wav.p_s_wavdata);
    
    PyObject* py_m = PyImport_AddModule("__main__"); 
    PyModule_AddObject(py_m, "wavdata", py_wavdata);
    PyModule_AddObject(py_m, "channels", Py_BuildValue("i", wav.n_channels));
    PyModule_AddObject(py_m, "samplerate", Py_BuildValue("l", wav.i64_samplerate));
    PyRun_SimpleString("wavdata.setflags(write=False)");
}

//All cepstrum related data exposed here
void PythonAnalyzer::setCepstrumInfo(cepinfo cep) {
    npy_intp dims[2] = {cep.i64_ceplen,  cep.i64_cepnum};
    PyObject* py_cepdata = PyArray_SimpleNewFromData(2,
                                                     dims,
                                                     NPY_CDOUBLE,
                                                     cep.p_cpd_cepdata);
    PyObject* py_m = PyImport_AddModule("__main__");
    PyModule_AddObject(py_m, "cepdata", py_cepdata);
    PyRun_SimpleString("cepdata.setflags(write=False)");
}

//FFT data exposed here
void PythonAnalyzer::setFFTInfo(fftinfo fft) {
    npy_intp dims[2] = {fft.i64_fftlen, fft.i64_fftnum};
    PyObject* py_fftdata = PyArray_SimpleNewFromData(2,
                                                    dims,
                                                    NPY_CDOUBLE,
                                                    fft.p_cpd_fftdata);
    PyObject* py_psd = PyArray_SimpleNewFromData(2,
                                                 dims,
                                                 NPY_DOUBLE,
                                                 fft.p_d_psd);
    PyObject* py_m = PyImport_AddModule("__main__");
    PyModule_AddObject(py_m, "fftdata", py_fftdata);
    PyModule_AddObject(py_m, "psd", py_psd);
    PyRun_SimpleString("fftdata.setflags(write=False)");
    PyRun_SimpleString("psd.setflags(write=False)");
}

//BFCC exposed here
void PythonAnalyzer::setBFCCInfo(bfccinfo bfcc) {
    npy_intp dims[2] = {bfcc.i64_bfcclen, bfcc.i64_bfccnum};
    PyObject* py_bfccdata = PyArray_SimpleNewFromData(2,
                                                     dims,
                                                     NPY_DOUBLE,
                                                     bfcc.p_d_bfccdata);
    PyObject* py_m = PyImport_AddModule("__main__");
    PyModule_AddObject(py_m, "bfccdata", py_bfccdata);
    PyRun_SimpleString("bfccdata.setflags(write=False)");
}

//Pick which values to expose to python interpreter
void PythonAnalyzer::setPythonMuBlockData(MuBlock* data) {
    this->setFileInfo(data);
    this->setFFTInfo(data->fft);
    this->setWAVInfo(data->wav);
    this->setCepstrumInfo(data->cep);
    this->setBFCCInfo(data->bfcc);
}

//Initialize a python interpreter which will have variables for all the things
//  mentioned in the above methods.
PythonAnalyzer::PythonAnalyzer(MuBlock* data) {
    mp_data = data;
    //Initialize Python
    Py_Initialize();
    //Initialize NumPy - REQUIRED! to use NumPy arrays
    import_array()
    this->setPythonMuBlockData(mp_data);
}
PythonAnalyzer::~PythonAnalyzer() { 
    //Cleanup interpreter when analysis is finished
    Py_Finalize();
}
//python_f is the path to the python file to run. This method is called from
//  main.cpp
std::string PythonAnalyzer::Run(std::string python_f) {
    std::stringstream ss;
    mp_python_f = PyFile_FromString(&python_f[0], "r");
    PyRun_SimpleFile(PyFile_AsFile(mp_python_f), &python_f[0]);
    ss << "PythonAnalyzer " << python_f << " has completed.\n";
    return ss.str();
}
