#pragma once

#include "..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\Gerenciadores\GerenciadorFisico.hpp"
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\Entidades\Personagens\Inimigo\InimigoFacil.hpp"
#include "..\Entidades\Obstaculos\Caixa.hpp"
#include "..\Entidades\Obstaculos\Gosma.hpp"
#include "..\Entidades\Obstaculos\Lava.hpp"

namespace Fases{
    class Fase: public Ente{
        protected:
            static Gerenciadores::GerenciadorGrafico* pGrafico;
            Gerenciadores::GerenciadorFisico gerenciadorFisico;
            Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
            Entidades::Personagens::Jogador* pJogador;
            Lista::ListaDeEntidades LE;
        public:
            Fase();
            ~Fase();
            void newJogador(sf::Vector2f pos, sf::Vector2f size);
            void newInimigo(sf::Vector2f pos, sf::Vector2f size);
            void newPlataforma(sf::Vector2f pos, sf::Vector2f size);
            void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
            void newGosma(sf::Vector2f pos, sf::Vector2f size);
            void newLava(sf::Vector2f pos, sf::Vector2f size);
            void draw();
            void executar();
            void update();
            virtual void loadMap() = 0;
    };
}