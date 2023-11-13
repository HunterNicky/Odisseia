#pragma once

#include "..\Jogador\Jogador.hpp"
#include "Lista/ListaDeEntidades.hpp"

namespace Entidades{
    namespace Personagens{
        class Inimigo : public Personagem{
        protected:
            Jogador *pJogador;
            void inicializa();
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const int id, Jogador* pJog);
            ~Inimigo();
            void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void move();
            void executar();
            void update();
            void tratarColisao(Entidade* entidade);
        };
    }
}