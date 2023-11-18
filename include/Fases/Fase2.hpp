#pragma once

#include "Fase.hpp"
#include <sstream>
#include <fstream>

namespace Fases{
    class Fase2: public Fase{
    private:

    public:
        Fase2();
        ~Fase2();
        void loadMap();
    };
}
