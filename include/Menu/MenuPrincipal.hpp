#pragma once

#include "Menu.hpp"
#include "..\Estados\Fases\Fase1.hpp"
#include "..\Estados\Estado.hpp"
#include "..\Estados\Jogo.hpp"

namespace Estados{
    class Jogo;
}

namespace Menu{
    class MenuPrincipal : public Menu{
        private:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            Estados::Jogo* pJogo;
            Estados::Fases::Fase1* fase1;
        public:
            MenuPrincipal(Estados::Jogo* pJogo);
            ~MenuPrincipal();
            void executar();
            void update(const double dt) override;
            void draw() override;
            void inicializaBotao();
    };
}
