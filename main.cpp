#include "Configurator.h"
#include "MuBlock.h"
#include "DataCollector.h"
#include "Process.h"
#include "PythonAnalyzer.h"

#include <iostream>
#include <sstream>
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
    
    bool repeat = false;
    config.lookup("runRepeatedly", &repeat);
    
    if(repeat) {
        std::cout << "Running in repeat mode - python blocks will be run multiple times" << std::endl;
    } else {
        std::cout << "Repeat mode off. This means each selected python block will run once." << std::endl;
    }

    bool loaded = true;
    unsigned int pos = 0;
    std::stringstream ss;

    do {
        do {
            std::string analyzer;
            ss << "analyzers.[" << pos << "]";
            loaded = config.lookup(ss.str(), &analyzer);
            if(loaded) {
                std::cout << "Now running analyzer " << analyzer << std::endl;
                ss.str("");
                ss << "Analyzers/" << analyzer;
                std::cout << test.Run(ss.str());
                ss.str("");
                pos++;
            }
        }
        while(loaded);
        //std::cout << test.Run("Analyzers/GMM.py");
        //std::cout << test.Run("Analyzers/DPGMM.py");
            std::cout << "Run finished, press enter to continue or press q to quit" << std::endl;
            if(std::getchar() == 'q') {
                break;
            }
            config.reloadConfig(); 
    }
    while(repeat);
    return 0;
}
