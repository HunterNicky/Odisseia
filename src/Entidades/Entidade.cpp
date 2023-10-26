#include "..\..\include\Entidades\Entidade.hpp"

Entidades::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f size, int id):
    Ente(pos, size), body(sf::RectangleShape(size)), id(id)
{
    body.setPosition(pos);
    body.setFillColor(sf::Color::Green);
}
Entidades::Entidade::~Entidade() {}

const int Entidades::Entidade::getId()const{return id;}

void Entidades::Entidade::setBody(sf::RectangleShape body)
{
    this->body = body;
}

sf::RectangleShape Entidades::Entidade::getBody()
{
    return body;
}

void Entidades::Entidade::draw()
{   

    pGrafico->draw(body);
}
