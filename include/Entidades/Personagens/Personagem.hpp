#pragma once

#include "..\Entidade.hpp"

namespace Entidades {
    class Entidade;
    namespace Personagens {
        class Personagem : public Entidade {
        protected:
            sf::Vector2f vel;
            sf::Vector2f acc;
            sf::Vector2f forca;
            sf::Vector2f prevPos;
            float massa;
            bool onFloor;
            int num_vidas;

        public:
            Personagem(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            ~Personagem();
            void move();
            virtual void operator--(const int dano) = 0;
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void verificaSolo(const sf::Vector2f mtv);
            void setVel(sf::Vector2f vel);
            void setAcc(sf::Vector2f acc);
            void setForca(sf::Vector2f forca);
            void setMassa(float massa);
            void setOnFloor(bool floor);
            void setPrevPos(sf::Vector2f prevPos);
            const sf::Vector2f getVel() const;
            const sf::Vector2f getAcc() const;
            const sf::Vector2f getForca() const;
            const sf::Vector2f getPrevPos() const;
            const float getMass() const;
            const int getNum_vidas() const;
            virtual void executar() = 0;
            virtual void update() = 0;
        };
    }
}
