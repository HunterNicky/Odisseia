#pragma once

#include "Obstaculo.hpp"
#include "..\Personagens\Personagem.hpp"

namespace Entidades{
    namespace Obstaculos{
        class Lava : public Obstaculo{
        private:
            
        public:
            Lava(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            ~Lava();
            void tratarColisao(Entidade* entidade);
            void executar();
            void update();  
        };
    }
}