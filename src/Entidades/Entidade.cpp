#include "..\..\include\Entidades\Entidade.hpp"

namespace Entidades{
    Entidades::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f size, ID id):
    Ente(pos, size),
    id(id){}
    Entidade::~Entidade(){}
    
    ID Entidade::getId()const{return id;}
    const sf::RectangleShape Entidade::getBody()const{return body;}
    void Entidade::draw(){pGrafico->draw(body);}
}