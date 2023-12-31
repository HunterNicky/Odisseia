#include "..\..\include\Fases\Fase.hpp"
#include <iostream>


namespace Fases{
    Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

    Fase::Fase():
    gerenciadorFisico(&LE){
        gerenciadorDeColisao.setList(&LE);
    }
    Fase::~Fase(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            LE.remove(i);
        }
        LE.clear();
    }
    void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
        pJogador = new Entidades::Personagens::Jogador(pos, size, 1);
        pJogador->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, size, 2, pJogador);
        pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, 3);
        pObstaculoFacil->setGerenciadorDeColisao(&gerenciadorDeColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
    }
    void Fase::executar(){
        if(pJogador){
            pGrafico->setViewCenter(pJogador->getBody()->getPosition());
            LE.updateAll();
            LE.drawAll();
            gerenciadorFisico.update();
            pGrafico->display();
            pGrafico->clear();
        }
    }
}
