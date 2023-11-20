#pragma once
#include "Fases/Fase2.hpp"
#include "Menu.hpp"
#include "Observadores/ControleMenu.hpp"

namespace Menu {
    class MenuPausa: public Menu{
        private:
            Observadores::ControleMenu* pControlePausa;
        public:
            MenuPausa();
            ~MenuPausa();
            void inicializaBotao();
            void executar();
            void update(const double dt);
    };
}