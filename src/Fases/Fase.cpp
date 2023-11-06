#include "..\..\include\Fases\Fase.hpp"
#include <iostream>

namespace Fases{

    Fase::Fase():
        gerenciadorFisico(&LE), Ente(sf::Vector2f(50.0f, 50.f), sf::Vector2f(50.0f, 50.0f))
    {
        pJogador = new Entidades::Personagens::Jogador(sf::Vector2f(200, 200), sf::Vector2f(20,60), Entidades::ID::jogador);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    Fase::~Fase(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            LE.remove(i);
        }
        LE.clear();
        gerenciadorDeColisao.setList(&LE);
    }
    void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
        pJogador = new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, size, Entidades::ID::Inimigo, pJogador);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, Entidades::ID::Caixa);
        LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
    }

    void Fase::draw()
    {   
    }

    void Fase::executar(){
        if(pJogador){
            //pGrafico->setViewCenter(pJogador->getBody()->getPosition());//esse é o jogador a posição 0
            //std::cout << pJogador->getPos().x <<"|"<< pJogador->getPos().y << std::endl;// ele não está atualizando a posição na lista
            //gerenciadorDeColisao.collisionDetection();
            LE.updateAll();
            LE.drawAll();
            gerenciadorFisico.update();
            pGrafico->display();
            pGrafico->clear();
        }
    }

    void Fase::update(){
        executar();
    }
}
