#include "..\..\..\include\Entidades\Projetil\Projetil.hpp"

namespace Entidades{
    //Dano do projetil
    int Projetil::dano(100);

    Projetil::Projetil(const sf::Vector2f pos, const Entidades::ID id, const bool direita):
        Entidade(pos, sf::Vector2f(10.0f, 10.0f), id)
    {
        if(direita){
            vel = sf::Vector2f(0.01f, 0.0f);
        }else{
            vel = sf::Vector2f(-0.01f, 0.0f);
        }
        body->setFillColor(sf::Color::Green);
    }

    Projetil::~Projetil(){

    }

    void Projetil::tratarColisao(Entidades::Entidade* entidade){
        if(entidade->getId() == Entidades::ID::jogador){
            std::cout << "Projetil colidiu com jogador!" << std::endl;
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(dano);
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