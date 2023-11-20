#pragma once

#include "Fases/Fase2.hpp"
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
            Fases::Fase2* fase2;
            Estados::Jogo* pJogo;
        public:
            MenuPrincipal(Estados::Jogo* pJogo);
            ~MenuPrincipal();
            void draw() override;
            void carregarJogo();
            void executar() override;
            void update(const double dt) override;
            //void draw() override;
            void inicializaBotao();
    };
}
