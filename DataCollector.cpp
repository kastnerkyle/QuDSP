#include "DataCollector.h"
/*
The function of the DataCollector class is to initialize a new MuBlock, and fill it with time series data from a file source. This file source ca be either .mp3 or one of the uncompressed formats supported by libsndfile (.wav, .aiff, etc).
*/

//Simple function to ensure proper cleanup for mpg123 library
void DataCollector::mpg123Cleanup() {
    mpg123_close(mp_mh);
    mpg123_delete(mp_mh);
    mpg123_exit();
}

//When constructo is called, create a new MuBlock
DataCollector::DataCollector() {
    MuBlock m_block;
}

//Destructor does nothing. The MuBlock instance handes all the freeing of data
DataCollector::~DataCollector() {
}

//Dirty hack - if filename ends with .mp3, run libmpg123, else use libsndfile
MuBlock* DataCollector::decode(std::string fname) {
    if (fname.substr(fname.find_last_of(".") + 1) == "mp3") {
        this->decodeMP3FromFile(fname);
    } else {
        this->decodeWAVFromFile(fname);
    }
    m_block.name = fname; 
    return &m_block; 
}

//May eventually implement fetch straight from URL
void DataCollector::fetchMP3FromURL() {
    //NYI
}

//Mp3 Decoding
void DataCollector::decodeMP3FromFile(std::string fname) {
    int err = MPG123_OK;
    char* file = (char *)fname.c_str(); 

    std::cout << "Input file: " << file << std::endl;
 
    //This whole method basically follows example code for mpg123. Some of the
    //  error checking might be excessive, but why the heck not?
    err = mpg123_init();    
    if (err != MPG123_OK || (mp_mh = mpg123_new(NULL, &err)) == NULL) {
        std::cerr << "Basic setup goes wrong: " << mpg123_plain_strerror(err) << std::endl;
        mpg123Cleanup();
        exit(99);
    }
    
    int encoding;
    if (mpg123_open(mp_mh, file) != MPG123_OK || mpg123_getformat(mp_mh, &m_block.wav.i64_samplerate, &m_block.wav.n_channels, &encoding) != MPG123_OK ) {
        std::cerr << "Trouble with mpg123: " << mpg123_strerror(mp_mh) << 
std::endl;
        exit(99);
    }
    
    mpg123_format_none(mp_mh);
    mpg123_format(mp_mh, m_block.wav.n_channels, m_block.wav.i64_samplerate, encoding);

    /*
    encoding != MPG123_ENC_SIGNED_16 ?
                std::cout << "Encoding is float." << std::endl <<
                std::cout << "Encoding is 16 bit signed." << std::endl;
        
    std::cout << "WAV will have " << m_block.wav.n_channels
              << " n_channels and " << m_block.wav.i64_samplerate
              << " Hz i64_samplerate." << std::endl;
    */

    mpg123_scan(mp_mh);

    //mpg123 returns an off_t, which represents bytes, so we need to convert to units of samples, which are short (16 bit)
    size_t size = (size_t)mpg123_length(mp_mh)*sizeof(short)/sizeof(unsigned char);
    
    //std::cout << size << " samples to read." << std::endl;
    //Store results in short[], because each sample is 16bit
    size_t done = 0;
    size_t total = size*m_block.wav.n_channels;
    m_block.wav.p_s_wavdata = new short[total];
    err = mpg123_read(mp_mh, (unsigned char*)m_block.wav.p_s_wavdata, total, &done);
    m_block.wav.i64_wavlen = size;
    /*
    err == MPG123_OK ?
           std::cout << m_block.wav.i64_wavlen << " samples in decoded array." << std::endl <<
           std::cerr << "MPG123 read error occured! << std::endl";
    */

    mpg123Cleanup();
}

//Wav decode
void DataCollector::decodeWAVFromFile(std::string fname) {
    //Once again, this method prety much uses the standard interface to libsndfile
    std::cout << "Input file: " << fname << std::endl;

    SF_INFO info;
    info.format = 0;
    SNDFILE* wav_fp;

    wav_fp = sf_open(fname.c_str(), SFM_READ, &info);
    if (!wav_fp) {
        std::cout << sf_strerror(wav_fp) << std::endl;
    }
   
    //Use short values, because wav samples are 16 bit 
    size_t total = info.channels*info.frames;
    m_block.wav.p_s_wavdata = new short[total];
    sf_read_short(wav_fp, m_block.wav.p_s_wavdata, total);
    m_block.wav.n_channels = info.channels;
    m_block.wav.i64_samplerate = info.samplerate;
    m_block.wav.i64_wavlen = total;
    sf_close(wav_fp);
}
