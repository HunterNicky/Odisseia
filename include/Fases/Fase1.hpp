#pragma once

#include "Fases/Fase.hpp"

namespace Fases{
    class Fase1 : public Fase{
    public:
        Fase1();
        ~Fase1();
        void recuperarJogada(nlohmann::json arquivoPersonagens);
        void loadMap();
        void draw();
        void update();
        void executar();
    };
}
