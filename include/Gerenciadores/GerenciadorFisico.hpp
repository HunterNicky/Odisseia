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
            double dt;
        public:
            ~GerenciadorFisico();
            void update(double dt);
            static GerenciadorFisico* getInstance();
            void calVel(Entidades::Entidade* entidade);
            void calAcc(Entidades::Entidade* entidade);
            void calColision(Entidades::Entidade* entidade, Entidades::Entidade* entidade1);
            void executarFisica(Entidades::Entidade* entidade);
            const sf::Vector2f calDrag(Entidades::Entidade* entidade) const;
            float getDeltaTime() const;
    };
}