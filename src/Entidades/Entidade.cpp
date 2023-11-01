#include "..\..\include\Entidades\Entidade.hpp"
namespace Entidades{
    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f size, const ID id):
        Ente(pos, size), id(id){
        body = new sf::RectangleShape(size);
        body->setPosition(pos);
    }

    Entidade::~Entidade(){
        delete (body);
    }

    const int Entidade::getId()const{return id;}

    void Entidade::setBody(sf::RectangleShape* body){this->body = body;}

    sf::RectangleShape* Entidade::getBody(){return body;}

    void Entidade::draw(){pGrafico->draw(body);}

}
