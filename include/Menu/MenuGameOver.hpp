#pragma once

#include "Menu.hpp"
#include "Fases/Fase1.hpp"

#define TAMANHO_TEXTO_GO_X 100.f
#define TAMANHO_TEXTO_GO_Y 100.f
#define POS_TEXTO_GO_X 640.f
#define POS_TEXTO_GO_Y 100.f

namespace Menu {
    class MenuGameOver : public Menu{
    private:

    public:
        MenuGameOver();
        ~MenuGameOver();	
        void reiniciarFase();
        void inicializaBotao();
        void executar();
        void update(const double dt);
        void draw();
    };
}