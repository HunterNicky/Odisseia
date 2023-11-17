#pragma once

#include "Estados/Fases/Fase2.hpp"
#include "Menu.hpp"
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
            Estados::Fases::Fase2* fase2;
        public:
            MenuPrincipal(Estados::Jogo* pJogo);
            ~MenuPrincipal();
            void draw() override;
            void carregarJogo();
            void executar();
            void update(const double dt) override;
            //void draw() override;
            void inicializaBotao();
    };
}
