#include "..\..\include\Entidades\Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
namespace Entidades{

    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
        Ente(pos, size), ID(id), body(new sf::RectangleShape(size)){
        body->setPosition(pos);
    }

    Entidade::~Entidade(){
        delete (body);
    }

    const ID Entidade::getId()const{return ID;}

    void Entidade::setBody(sf::RectangleShape* body){this->body = body;}

    sf::RectangleShape* Entidade::getBody(){return body;}

    void Entidade::draw(){pGrafico->draw(body);}

    void Entidade::setGerenciadorDeColisao(Gerenciadores::GerenciadorDeColisao* gColisao){this->gColisao = gColisao;}

}
