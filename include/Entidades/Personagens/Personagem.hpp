#pragma once

#include "..\Entidade.hpp"

namespace Entidades{
    namespace Personagens{
        class Personagem: public Entidade {
        protected:
            sf::Vector2f vel;
            sf::Vector2f acc;
            sf::Vector2f forca;
            float massa;
            int num_vidas;
        public:
            Personagem(const sf::Vector2f pos, const sf::Vector2f size, int id);
            ~Personagem();
            void move();
            virtual void executar() = 0;
            virtual void update() = 0;
            void setVel(sf::Vector2f vel);
            void setAcc(sf::Vector2f acc);
            void setMassa(float massa);
            const sf::Vector2f getVel() const;
            const sf::Vector2f getAcc() const;
            const sf::Vector2f getForca() const;
            const float getMass() const;
        };
    }
}