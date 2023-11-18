#pragma once

#include "Fase.hpp"
#include <sstream>
#include <fstream>
namespace Fases{
    class Fase1 : public Fase{
        public:
            Fase1();
            ~Fase1();
            void loadMap();
            void draw();
            void update();
            void executar();
    };
}
