#pragma once

#include "..\Entidade.hpp"
#include "Entidades/Entidade.hpp"


namespace Entidades {
    namespace Personagens {
        class Personagem : public Entidade {
        protected:
            bool onFloor;
            float jumpTime;
            int num_vidas;

        public:
            Personagem(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            ~Personagem();
            void move();
            virtual void inicializa() = 0;
            virtual void operator--(const int dano) = 0;
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void verificaSolo(const sf::Vector2f mtv);
            void setOnFloor(const bool floor);
            const float getJumpTime() const;
            const int getNum_vidas() const;
            virtual void salvar(std::ostringstream* entrada) = 0;
            virtual void executar() = 0;
            virtual void update() = 0;
        };
    }
}
