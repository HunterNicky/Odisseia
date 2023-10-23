#include "..\include\Ente.hpp"

Ente::Ente(sf::Vector2f pos, sf::Vector2f size):
pos(pos),
size(size){}

Ente::~Ente(){}

sf::Vector2f Ente::getPos(){return pos;}

sf::Vector2f Ente::getSize(){return size;}

void Ente::setPos(sf::Vector2f pos){this->pos = pos;}

void Ente::setSize(sf::Vector2f size){this->size = size;}