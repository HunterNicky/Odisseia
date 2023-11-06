#pragma once

#include "..\Jogador\Jogador.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define RAIO_PERS_X 200.0f
#define RAIO_PERS_Y 200.0f
namespace Entidades{
    namespace Personagens{
        class Inimigo : public Personagem{
        protected:
            Entidades::Personagens::Jogador *pJogador;
            int moveAleatorio;
            void inicializa();
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const ID id, Entidades::Personagens::Jogador* pJog);
            ~Inimigo();
            void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void movimentoAleatorio();
            void move();
            void executar();
            void update();
        };
    }
}