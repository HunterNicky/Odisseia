#pragma once

#include <SFML/Graphics.hpp>
#include "..\..\include\Entidades\Personagens\Personagem.hpp"
#include "..\..\include\Entidades\Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades{
        class Entidade;
}

namespace Gerenciadores{
    class GerenciadorFisico{
        private:
            GerenciadorFisico();
            static GerenciadorFisico* instance;
            double dt, alpha;
        public:
            ~GerenciadorFisico();
            void update(double dt, double alpha);
            static GerenciadorFisico* getInstance();
            void calVel(Entidades::Personagens::Personagem* personagem);
            void calAcc(Entidades::Personagens::Personagem* personagem);
            void calColision(Entidades::Personagens::Personagem* personagem, Entidades::Personagens::Personagem* personagem1);
            void executarFisica(Entidades::Entidade* entidade);
            const sf::Vector2f calDrag(Entidades::Personagens::Personagem* personagem) const;
            float getDeltaTime() const;
    };
}