#pragma once

#include "Fase.hpp"
#include <sstream>
#include <fstream>
namespace Estados{
    namespace Fases{
        class Fase1 : public Fase{
            public:
                Fase1();
                ~Fase1();
                void loadMap();
                //virtual void resetEstate() = 0;
        };
    }
}