#pragma once

#include "..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\Gerenciadores\GerenciadorFisico.hpp"
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "..\Entidades\Obstaculos\ObstaculoFacil.hpp"
#include "..\Observadores\ControleJogador.hpp"
#include "..\Gerenciadores\GerenciadorDeEvento.hpp"

namespace Fases{
    class Fase{
        private:
            static Gerenciadores::GerenciadorGrafico* pGrafico;
            static Gerenciadores::GerenciadorDeEvento* pEvento;
            Observadores::ControleJogador* controle;
            Gerenciadores::GerenciadorFisico gerenciadorFisico;
            Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
            Entidades::Personagens::Jogador* pJogador;
            Lista::ListaDeEntidades LE;
        public:
            Fase();
            ~Fase();
            void newJogador(sf::Vector2f pos, sf::Vector2f size);
            void newInimigo(sf::Vector2f pos, sf::Vector2f size);
            void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
            void executar();
            virtual void loadMap() = 0;
    };
}