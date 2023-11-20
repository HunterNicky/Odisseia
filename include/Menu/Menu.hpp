#pragma once 

#include <list>
#include "..\Ente.hpp"
#include "..\Observadores\ControleMenu.hpp"
#include "..\Estados\Estado.hpp"
#include "Botoes/Botao.hpp"

namespace Observadores{
    class ControleMenu;
}

namespace Menu{
    class Menu : public Estados::Estado{
        protected:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            static Observadores::ControleMenu* pControleMenu;
            std::list<Botoes::Botao*> lBotao;
            std::list<Botoes::Botao*>::iterator it;
            unsigned int numOpc;
            unsigned int numSelec;
        public:
            Menu(const int id, int numOpc);
            virtual ~Menu();
            virtual void executar() = 0;
            void select(const bool direcao);    
            void update(const double dt);
            void draw();
    };
}