#include "..\..\..\include\Estados\Fases\Fase.hpp"
#include <iostream>

namespace Estados{
    namespace Fases{
        Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
        Gerenciadores::GerenciadorDeEvento* Fase::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
        Estados::MaquinaDeEstado* Fase::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

        Fase::Fase():
            Estado(pMaquinaDeEstado, 1), gerenciadorFisico(&LE){
            pJogador = nullptr;
            controle = new Observadores::ControleJogador(pJogador);
            gerenciadorDeColisao.setList(&LE);
            pEvento->addObserver(static_cast<Observadores::Observer*>(controle));
        }
        Fase::~Fase(){
            for(unsigned int i = 0; i < LE.getSize(); i++){
                LE.remove(i);
            }
            LE.clear();
            pGrafico->close();
        }
        void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
            pJogador = new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
            pJogador->setGerenciadorDeColisao(&gerenciadorDeColisao);
            controle->setJogador(pJogador);
            LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
        }
        void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::InimigoFacil* pInimigo = new Entidades::Personagens::InimigoFacil(pos, size, Entidades::ID::Inimigo, pJogador);
            pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, Entidades::ID::Plataforma);
            pObstaculoFacil->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
        }
        void Fase::update(){
            executar();
        }
        void Fase::executar(){
            if(pJogador){
                pGrafico->setViewCenter(pJogador->getBody()->getPosition());
                pEvento->stage();
                LE.updateAll();
                LE.drawAll();
                gerenciadorFisico.update();
                pGrafico->display();
                pGrafico->clear();
            }
        }
    }
}
