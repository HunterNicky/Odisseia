#pragma once 

#include <list>
#include "GerenciadorGrafico.hpp"
#include "..\Observadores\Observer.hpp"

namespace Gerenciadores{
    class GerenciadorDeEvento{
        private:
            static GerenciadorGrafico* pGrafico;
            static GerenciadorDeEvento* pEvento;
            std::list<Observadores::Observer*> lObserver;
            bool removido;
            GerenciadorDeEvento();
        public:
            ~GerenciadorDeEvento();
            static GerenciadorDeEvento* getInstance();
            void addObserver(Observadores::Observer* observer);
            void removeObserver(Observadores::Observer* observer);
            void stage();
    };
}