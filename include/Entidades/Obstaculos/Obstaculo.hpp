#pragma once

#include "..\Entidade.hpp"
namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        protected:
            bool danoso;
        public:
            Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const Entidades::ID id);
            ~Obstaculo();
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void tratarColisao(Entidade* entidade) ;
        };
    }
}
