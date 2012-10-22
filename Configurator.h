#ifndef _CONFIGURATOR_H_
#define _CONFIGURATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <libconfig.h++>
#include <string>

class Configurator {
   private:
        libconfig::Config m_cfg;
        std::string m_fname;
        void checkConfig();
   public:
        Configurator();
        ~Configurator();
        void reloadConfig();
        template <typename label, typename quantifier>
        bool lookup(label key, quantifier* value) {
            return this->m_cfg.lookupValue(key, reinterpret_cast< quantifier& >(*value));
        };
};
#endif
