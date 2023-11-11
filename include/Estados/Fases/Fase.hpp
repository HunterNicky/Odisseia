#pragma once

#include "..\..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\..\Gerenciadores\GerenciadorFisico.hpp"
#include "..\..\Lista\ListaDeEntidades.hpp"
#include "..\..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\..\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "..\..\Entidades\Obstaculos\ObstaculoFacil.hpp"
#include "..\..\Observadores\ControleJogador.hpp"
#include "..\..\Gerenciadores\GerenciadorDeEvento.hpp"
#include "..\Estado.hpp"
#include "..\MaquinaDeEstado.hpp"

namespace Estados{
    namespace Fases{
        class Fase : public Estados::Estado{
            private:
                static Gerenciadores::GerenciadorGrafico* pGrafico;
                static Gerenciadores::GerenciadorDeEvento* pEvento;
                static MaquinaDeEstado* pMaquinaDeEstado;
                Observadores::ControleJogador* controle;
                Gerenciadores::GerenciadorFisico gerenciadorFisico;
                Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
                Entidades::Personagens::Jogador* pJogador;
                Lista::ListaDeEntidades LE;
                double dt, alpha;
            public:
                Fase();
                ~Fase();
                void newJogador(sf::Vector2f pos, sf::Vector2f size);
                void newInimigo(sf::Vector2f pos, sf::Vector2f size);
                void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
                void update(double dt, double alpha);
                void executar();
                virtual void draw() = 0;
                //virtual void resetEstate() = 0;
                virtual void loadMap() = 0;
        };
    }
}