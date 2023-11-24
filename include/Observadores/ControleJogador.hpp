#pragma once

#include "Observer.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Estados\MaquinaDeEstado.hpp"
#include "Menu/MenuGameOver.hpp"
#include "Menu/MenuPausa.hpp"

namespace Fases {
    class Fase;

}
namespace Entidades{
    namespace Personagens{
        class Jogador;
    }
}

namespace Observadores{
    class ControleJogador : public Observer{
        private:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            Entidades::Personagens::Jogador* pJogador;
            Fases::Fase* pFase;
            std::string pular, esquerda, direita, correr;
            std::string fechar;
        public:
            ControleJogador(Entidades::Personagens::Jogador* pJogador, Fases::Fase* pFase);
            ~ControleJogador();
            void setJogador(Entidades::Personagens::Jogador* pJogador);
            void jogadorNeutralizado();
            const bool proximaFase();
            void notifyPressed(const sf::Keyboard::Key key);
            void notifyReleased(const sf::Keyboard::Key key);
    };
}