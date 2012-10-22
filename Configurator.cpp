#include "Configurator.h"
/* 
The purpose of the Configurator class is to handle the parsing and possible bounds/validity checking of the configuration file ProcessMusic.cfg
*/

//Empty constructor assumes file is called ProcessMusic.cfg and exists in the current directory
Configurator::Configurator() {
    this->m_fname = "ProcessMusic.cfg";
    this->checkConfig();
}

Configurator::~Configurator() {
}

void Configurator::checkConfig() {
    try {
        m_cfg.readFile(this->m_fname.c_str());
    }
    catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Unable to read config file " << this->m_fname << " . Check that file exists and has proper permissions!" << std::endl;
    }
    catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error in config file " << pex.getFile() << ", at line " << pex.getLine() << ", with error " << pex.getError() << std::endl;
    }
}

void Configurator::reloadConfig() {
    this->checkConfig();
}
