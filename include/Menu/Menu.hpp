#pragma once 

#include <list>
#include "..\Ente.hpp"
#include "..\Observadores\ControleMenu.hpp"
#include "Botoes/Botao.hpp"

namespace Observadores{
    class ControleMenu;
}

namespace Menu{
    class Menu : public Ente{
        protected:
            Observadores::ControleMenu* controleMenu;
            std::list<Botoes::Botao*> lBotao;
            std::list<Botoes::Botao*>::iterator it;
            unsigned int numOpc;
            unsigned int numSelec;
        public:
            Menu();
            virtual ~Menu();
            virtual void executar() = 0;
            void select(const bool direcao);    
            void update();
            void draw();
    };
}