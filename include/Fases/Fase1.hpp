#pragma once

#include "Fase.hpp"
#include <string>
#include <sstream>
#include <fstream>

namespace Fases{
    class Fase1 : public Fase{
        private:
        public:
            Fase1();
            ~Fase1();
            void loadMap();
    };
}