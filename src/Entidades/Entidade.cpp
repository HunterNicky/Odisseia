#include "..\..\include\Entidades\Entidade.hpp"

Entidades::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f size, int id):
    Ente(pos, size),
    id(id)
{
}
Entidades::Entidade::~Entidade() {}

const int Entidades::Entidade::getId()const{return id;}

void Entidades::Entidade::setBody(sf::RectangleShape body)
{
    this->body = body;
}

sf::RectangleShape Entidades::Entidade::getBody()
{
    return sf::RectangleShape(body);
}

void Entidades::Entidade::draw()
{   
    //Arrumar
    pGrafico->draw(body);
}
