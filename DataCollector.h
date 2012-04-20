#ifndef _DATACOLLECTOR_H_
#define _DATACOLLECTOR_H_

#include <assert.h>
#include <mpg123.h>
#include <sndfile.h>
#include <iostream>
#include "MuBlock.h"

class DataCollector {
    private:
        MuBlock m_block;
        mpg123_handle* mp_mh;
        void mpg123Cleanup();
        void fetchMP3FromURL();
        void decodeMP3FromFile(std::string fname);
        void decodeWAVFromFile(std::string fname);
 
    public:
        DataCollector();
        ~DataCollector();
        MuBlock* Decode(std::string fname);
};
#endif
