#pragma once

#include "..\Entidade.hpp"
#include "Entidades/Entidade.hpp"
namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        protected:
            bool danoso;
        public:
            Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const Entidades::ID id);
            ~Obstaculo();
            virtual void verificaSolo(sf::Vector2f mtv);
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void salvar(std::ostringstream* entrada) = 0;
        };
    }
}
