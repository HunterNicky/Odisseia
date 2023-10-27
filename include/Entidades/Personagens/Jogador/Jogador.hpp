#pragma once

#include "..\Personagem.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem {
        private:
            void inicializa();
        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f size, int id);
            ~Jogador();
            void move();
            void executar();
            void update();
        };
    }
}
