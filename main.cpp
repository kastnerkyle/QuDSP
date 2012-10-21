#include "Configurator.h"
#include "MuBlock.h"
#include "DataCollector.h"
#include "Process.h"
#include "PythonAnalyzer.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Missing the path to the mp3!" << std::endl;
        return -1;
    }
    
    const int64_t fftlen = 2048;
    static_assert(WINDOWLEN == fftlen, "Window.h has not been generated for \
                                        this size, please re-run genWindow.py");

    std::string f(argv[1]);

    Configurator config;
    config.readConfig();

    //Initialize a MuBlock with data from fname
    DataCollector data;
    MuBlock* mb = data.decode(f);
   
    //Throw out songs longer than 10 minutes, due to RAM (>8 GB usage on MuchLikeMescaline) 
    if ((mb->wav.i64_wavlen/mb->wav.i64_samplerate) > 600) {
        return 1;
    }

    //Perform Blackman-Harris windowed FFTs of length fftlen
    Process proc;
    proc.BFCC(mb, fftlen, fftlen);
    
    //Run Python blocks here...
    PythonAnalyzer test(mb);
    
    std::cout << test.Run("Analyzers/GMM.py");
    //std::cout << test.Run("Analyzers/DPGMM.py");
    return 0;
}
