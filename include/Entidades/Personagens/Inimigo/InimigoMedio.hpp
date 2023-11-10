#pragma once

#include "Inimigo.hpp"
#include "..\..\Projetil\Projetil.hpp"
#include <math.h>

#define RANGE 200.0f
namespace Entidades{
    namespace Personagens{
        class InimigoMedio: public Inimigo{
        private:
           //Entidades::Projetil* pProj;
            int dano;
            int moveAleatorio;
            void inicializa();
        public:
            InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~InimigoMedio();
            void operator--(const int dano);
            void movimentoAleatorio();
            void atirarProjetil(sf::Vector2f pos);
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
        };
    }
}