#include "..\..\include\Fase\Fase.hpp"

namespace Fase{
    Fase::Fase():
        Ente(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f))
    {}
    Fase::~Fase(){}

    void Fase::createInimigo(const sf::Vector2f pos){
        Entidades::Personagens::Jogador* pJogador = nullptr;
        Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, sf::Vector2f(40.0f, 40.0f), Entidades::ID::Inimigo, pJogador);
        if(pInimigo)
        {
            listaPersonagens.push_back(static_cast<Entidades::Entidade*> (pInimigo)); 
        }
    }

    void Fase::createJogador(const sf::Vector2f pos){
        Entidades::Personagens::Jogador* pJogador = new Entidades::Personagens::Jogador(pos, sf::Vector2f(50.0f, 50.0f), Entidades::ID::jogador);
        if(pJogador)
        {
            listaPersonagens.push_back(static_cast<Entidades::Entidade*> (pJogador));
        }
    }
    void Fase::createPlataforma(const sf::Vector2f pos){
        Entidades::Obstaculos::ObstaculoFacil* pPlataforma = new Entidades::Obstaculos::ObstaculoFacil(pos, sf::Vector2f(300.0f, 50.0f), Entidades::ID::ObstaculoFacil);
        if(pPlataforma)
        {
            listaPersonagens.push_back(static_cast<Entidades::Entidade*> (pPlataforma));
        }
    }

    void createBox(const sf::Vector2f pos){
  
    }

    void Fase::draw(){
        listaPersonagens.drawAll();
    }
    void Fase::executar(){
        listaPersonagens.updateAll();
    }
    void Fase::update(){
        executar();
    }
}
