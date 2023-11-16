#pragma once

#include "Fase.hpp"

namespace Estados{
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
}