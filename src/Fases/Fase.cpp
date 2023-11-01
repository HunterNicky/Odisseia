#include "..\..\include\Fases\Fase.hpp"
#include <iostream>


namespace Fases{
    Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

    Fase::Fase():
    gerenciadorDeColisao(&LE),
    gerenciadorFisico(&LE){
        pJogador = new Entidades::Personagens::Jogador(sf::Vector2f(200, 200), sf::Vector2f(20,60), 1);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    Fase::~Fase(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            LE.remove(i);
        }
        LE.clear();
    }
    void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
        pJogador = new Entidades::Personagens::Jogador(pos, size, 1);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, size, 2, pJogador);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, 3);
        LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
    }
    void Fase::executar(){
        if(pJogador){
            pGrafico->setViewCenter(LE[0]->getPos());//esse é o jogador a posição 0
            std::cout << LE[0]->getPos().x <<"|"<< LE[0]->getPos().y << std::endl;// ele não está atualizando a posição na lista
            gerenciadorDeColisao.checkCollision();
            LE.updateAll();
            LE.drawAll();
            gerenciadorFisico.update();
            pGrafico->display();
            pGrafico->clear();
        }
    }
}
