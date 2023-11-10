#include "..\..\..\include\Entidades\Projetil\Projetil.hpp"

namespace Entidades{
    //Dano do projetil
    int Projetil::dano(20);

    Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
        Entidade(pos, size, id)
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

    void Projetil::draw(){
        pGrafico->draw(body);
    }

    void Projetil::executar(){

    }

    void Projetil::update(){
        executar();
    }
}