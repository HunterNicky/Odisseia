#pragma once

#include "Estados/Fases/Fase2.hpp"
#include "Menu.hpp"
#include "Fases/Fase1.hpp"
#include "..\Estados\Estado.hpp"
#include "..\Estados\Jogo.hpp"

namespace Estados{
    class Jogo;
}

namespace Menu{
    class MenuPrincipal : public Menu{
        private:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            Fases::Fase1* fase1;
            Estados::Jogo* pJogo;
            Estados::Fases::Fase1* fase1;
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
