#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"

Entidades::Personagens::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, int id):
    Entidade(pos, size, id)    
{
}
Entidades::Personagens::Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::setVel(sf::Vector2f vel)
{
    this->vel = vel;
}

const sf::Vector2f Entidades::Personagens::Personagem::getVel() const
{
    return sf::Vector2f(vel);
}
