#include "..\include\Ente.hpp"
#include "Ente.hpp"

Gerenciadores::GerenciadorGrafico* Ente::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Ente::Ente(const sf::Vector2f pos, const sf::Vector2f size):
    pos(pos), size(size)
{

}

Ente::~Ente(){}

sf::Vector2f Ente::getPos(){return pos;}

sf::Vector2f Ente::getSize(){return size;}

void Ente::setPos(const sf::Vector2f pos){this->pos = pos;}

void Ente::setSize(const sf::Vector2f size) {this->size = size;}