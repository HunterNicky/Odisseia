#pragma once

#include "Observer.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador;
    }
}

namespace Observadores{
    class ControleJogador : public Observer{
        private:
            Entidades::Personagens::Jogador* pJogador;
            std::map<std::string, bool> keyPressed;
            std::string pular, esquerda, direita;
        public:
            ControleJogador(Entidades::Personagens::Jogador* pJogador);
            ~ControleJogador();
            void setJogador(Entidades::Personagens::Jogador* pJogador);
            void notifyPressed(std::string key);
            void notifyReleased(std::string key);
    };
}