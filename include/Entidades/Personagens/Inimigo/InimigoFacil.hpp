#pragma once

#include "Inimigo.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

namespace Entidades{
    namespace Personagens{
        class InimigoFacil : public Inimigo{
        private:
            int range;
            int moveAleatorio;
            void inicializa();
        public:
            InimigoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~InimigoFacil();
            void operator--();
            void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void movimentoAleatorio();
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
        };
    }
}