#pragma once

#include "..\Personagem.hpp"
#include "Entidades/Entidade.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem {
        private:
            void inicializa();
        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f size, const int id);
            ~Jogador();
            void move();
            void pular();
            void direcionar(bool side);
            void parar();
            void executar();
            void update();
            void tratarColisao(Entidade* entidade);
        };
    }
}
