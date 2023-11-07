#pragma once

#include "Obstaculo.hpp"
namespace Entidades{
    namespace Obstaculos
    {
        class ObstaculoFacil : public Obstaculo{
        private:

        public:
            ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f, const Entidades::ID id);
            ~ObstaculoFacil();
            void tratarColisao(Entidade* entidade);
            void executar();
            void update();
            void tratarColisao();
        };
    }
    
}