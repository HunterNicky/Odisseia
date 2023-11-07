#pragma once

#include "Obstaculo.hpp"

namespace Entidades{
    namespace Obstaculos{
        class Gosma : public Obstaculo{
        private:
            int slow;
        public:
            Gosma(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            ~Gosma();
            void tratarColisao();
            void executar();
            void update();
        };
    }
}