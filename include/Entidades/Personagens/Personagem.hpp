#pragma once

#include "..\Entidade.hpp"

namespace Entidades{
    namespace Personagens{
        class Personagem: public Entidade {
        protected:
            sf::Vector2f vel;
            int num_vidas;
        public:
            Personagem(const sf::Vector2f pos, const sf::Vector2f size, const int id);
            ~Personagem();
            virtual void move() = 0;
            virtual void executar() = 0;
            virtual void update() = 0;
            void setVel(sf::Vector2f veloc);
            const sf::Vector2f getVel() const;
        };
    }
}