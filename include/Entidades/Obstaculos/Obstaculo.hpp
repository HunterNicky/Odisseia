#pragma once

#include "..\Entidade.hpp"
#include "Entidades/Entidade.hpp"
namespace Entidades{
    namespace Obstaculos{
        class Obstaculo: public Entidade{
        private:
            //...
        public:
            Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const int id);
            ~Obstaculo();
            virtual void verificaSolo(sf::Vector2f mtv);
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void tratarColisao(Entidade* entidade) = 0;
            //...
        };
    }
}
