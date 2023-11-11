#include "..\..\..\include\Entidades\Projetil\Projetil.hpp"

namespace Entidades{
    //Dano do projetil
    int Projetil::dano(20);

    Projetil::Projetil():
        Entidade(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 10.0f), Entidades::ID::Projetil), vel(sf::Vector2f(0.1f, 0.01f))
    {
        body->setFillColor(sf::Color::Green);
        
    }

    Projetil::~Projetil(){

    }

    void Projetil::tratarColisao(Entidades::Entidade* entidade){
        if(entidade->getId() == Entidades::ID::jogador){
            std::cout << "Projetil colidiu com jogador!" << std::endl;
        }
    }

    void Projetil::verificaSolo(const sf::Vector2f mtv){

    }

    void Projetil::setPersonagem(Entidades::Personagens::Personagem* pPers){
        this->pPers = pPers;
    }

    void Projetil::draw(){
        pGrafico->draw(body);
    }

    void Projetil::executar(){
        body->move(vel);
        gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
    }

    void Projetil::update(){
        executar();
    }
}