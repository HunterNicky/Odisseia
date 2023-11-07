#include "..\..\include\Fases\Fase.hpp"
#include <iostream>

namespace Fases{
    Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

    Fase::Fase():
        Ente(), gerenciadorFisico(&LE)
    {
        gerenciadorDeColisao.setList(&LE);
        //pJogador = new Entidades::Personagens::Jogador(sf::Vector2f(200.f, 200.f), sf::Vector2f(20.f,60.f), Entidades::ID::jogador);
        //LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    Fase::~Fase(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            LE.remove(i);
        }
        LE.clear();
    }
    void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
        pJogador = new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
        pJogador->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::InimigoFacil* pInimigo = new Entidades::Personagens::InimigoFacil(pos, size, Entidades::ID::Inimigo, this->pJogador);
        pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, Entidades::ID::Plataforma);
        pObstaculoFacil->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
    }

    void Fase::draw(){   //Verifica vida dos personagens
        Entidades::Personagens::Personagem* pPers = nullptr;
        for(unsigned int i = 0; i < LE.getSize(); i++){
            if((LE[i]->getId() == Entidades::ID::Inimigo) || (LE[i]->getId() == Entidades::ID::jogador)){
                pPers = static_cast<Entidades::Personagens::Personagem*>(LE[i]);
                if(pPers->getNum_vidas() < 0){
                    LE.remove(i);
                }
            }
        }
    }

    void Fase::executar(){
        if(pJogador){
            pGrafico->setViewCenter(pJogador->getBody()->getPosition());//esse é o jogador a posição 0
            LE.updateAll();
            LE.drawAll();
            gerenciadorFisico.update();
            draw();
            pGrafico->display();
            pGrafico->clear();
        }
    }

    void Fase::update(){
        executar();
    }
}
