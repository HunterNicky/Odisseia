#pragma once

#include "Entidades/Personagens/Jogador/Jogador.hpp"
//#include "Estados/Estado.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Gerenciadores/GerenciadorDeColisao.hpp"
#include "Gerenciadores/GerenciadorDeEvento.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include "Observadores/ControleJogador.hpp"
#include "Entidades/Personagens/Inimigo/Inimigo.hpp"
#include "Entidades/Personagens/Inimigo/InimigoFacil.hpp"
#include "Entidades/Personagens/Inimigo/InimigoMedio.hpp"
#include "Entidades/Personagens/Inimigo/InimigoDificil.hpp"
#include "Entidades/Projetil/Projetil.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"
#include "Entidades/Obstaculos/Lava.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hpp"

namespace Fases{
    class Fase : public Estados::Estado{
        protected:
            static Gerenciadores::GerenciadorGrafico* pGrafico;
            static Gerenciadores::GerenciadorDeEvento* pEvento;
            static Gerenciadores::GerenciadorFisico* pFisico;
            static Gerenciadores::GerenciadorDeColisao* pColisao;
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            Observadores::ControleJogador* controle;
            Entidades::Personagens::Jogador* pJogador;
            Lista::ListaDeEntidades LE;
            double dt;
        public:
            Fase();
            ~Fase();
            void newJogador(sf::Vector2f pos, sf::Vector2f size);
            void newInimigo(sf::Vector2f pos, sf::Vector2f size);
            void newInimigoMedio(sf::Vector2f pos, sf::Vector2f size);
            void newChefao(sf::Vector2f pos, sf::Vector2f size);
            void newProjetil(sf::Vector2f pos, const bool direita);
            //void newPlataforma(sf::Vector2f pos, sf::Vector2f size);
            //void newGosma(sf::Vector2f pos, sf::Vector2f size);
            virtual void recuperarJogada(nlohmann::json arquivoPersonagens) = 0;
            void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
            void newLava(sf::Vector2f pos, sf::Vector2f size);
            void updateVida();
            void update(double dt);
            void executar();
            void draw();
            //virtual void resetEstate() = 0;
            virtual void loadMap() = 0;
    };
}
