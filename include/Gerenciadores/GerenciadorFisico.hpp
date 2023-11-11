#pragma once

#include <SFML/Graphics.hpp>
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\..\include\Entidades\Personagens\Personagem.hpp"
#include "..\..\include\Entidades\Entidade.hpp"


namespace Gerenciadores{
    class GerenciadorFisico{
        private:
            Lista::ListaDeEntidades* LE;
            sf::Clock clock;
            float deltaTime;
        public:
            GerenciadorFisico(Lista::ListaDeEntidades* listaEntidades);
            ~GerenciadorFisico();
            void update(double dt, double alpha);
            void calVel(Entidades::Personagens::Personagem* personagem);
            void calAcc(Entidades::Personagens::Personagem* personagem);
            float getDeltaTime() const;
    };
}