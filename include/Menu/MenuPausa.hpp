#pragma once

#include "Menu.hpp"

namespace Fases {
    class Fase;
}

#define TAM_TEXTO_PAUSE_X 100.f
#define TAM_TEXTO_PAUSE_Y 100.f
#define POS_TEXTO_PAUSE_X 640.f
#define POS_TEXTO_PAUSE_Y 100.f
namespace Menu {
    class MenuPausa: public Menu{
    private:
        Fases::Fase* pFase;
    public:
        MenuPausa(Fases::Fase* pFase);
        ~MenuPausa();
        void inicializaBotao();
        void executar();
        void update(const double dt);
        void draw();
    };
}