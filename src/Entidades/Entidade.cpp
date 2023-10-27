#include "..\..\include\Entidades\Entidade.hpp"
namespace Entidades{
    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f size, int id):
        Ente(pos, size), body(sf::RectangleShape(size)), id(id)
    {
        body.setPosition(pos);
        body.setFillColor(sf::Color::Green);
    }
    Entidade::~Entidade() {}

    const int Entidade::getId()const{return id;}

    void Entidade::setBody(sf::RectangleShape body)
    {
        this->body = body;
    }

    const sf::RectangleShape Entidade::getBody()
    {
        return body;
    }

    void Entidade::draw()
    {   
        pGrafico->draw(body);
    }

}
