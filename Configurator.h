#ifndef _CONFIGURATOR_H_
#define _CONFIGURATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <libconfig.h++>
#include <string>

class Configurator {
   private:
        libconfig::Config cfg;
        std::string fname;
        void checkConfig();
   public:
        Configurator();
        ~Configurator();
        void reloadConfig();
        template <typename label, typename quantifier>
        bool lookup(label key, quantifier* value) {
            return cfg.lookupValue(key, reinterpret_cast< quantifier& >(*value));
        };
};
#endif
