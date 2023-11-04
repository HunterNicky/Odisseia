#pragma once

#include "Obstaculo.hpp"

namespace Entidades{
    namespace Obstaculos{
        class Lava : public Obstaculo{
        private:
            
        public:
            Lava(const sf::Vector2f pos, const sf::Vector2f size, const ID id);
            ~Lava();
            void executar();
            void update();
        };
    }
}