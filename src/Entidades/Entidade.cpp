#include "..\..\include\Entidades\Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
namespace Entidades{
    Gerenciadores::GerenciadorFisico* Entidade::gFisico = Gerenciadores::GerenciadorFisico::getInstance();

    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f size, int id):
        Ente(pos, size), id(id), body(new sf::RectangleShape(size)){
        body->setPosition(pos);
    }

    Entidade::~Entidade(){
        delete (body);
    }

    const int Entidade::getId()const{return id;}

    void Entidade::setBody(sf::RectangleShape* body){this->body = body;}

    sf::RectangleShape* Entidade::getBody(){return body;}

    void Entidade::draw(){pGrafico->draw(body);}

    void Entidade::setGerenciadorDeColisao(Gerenciadores::GerenciadorDeColisao* gColisao){this->gColisao = gColisao;}

}
