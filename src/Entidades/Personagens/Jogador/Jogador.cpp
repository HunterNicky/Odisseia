#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"


void Entidades::Personagens::Jogador::inicializa()
{
    Entidades::Personagens::Personagem::setVel(sf::Vector2f(0.1f, 0.1f));
}

Entidades::Personagens::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam, int id):
    Personagem(pos, tam, id)
{
    Entidades::Entidade::setBody(sf::RectangleShape(tam));
    Entidades::Entidade::getBody().setPosition(pos);
    Entidades::Entidade::getBody().setFillColor(sf::Color::Green);
    inicializa();
}

Entidades::Personagens::Jogador::~Jogador()
{
}

void Entidades::Personagens::Jogador::move()
{
    sf::Vector2f vel = Entidades::Personagens::Personagem::getVel();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Entidades::Entidade::getBody().move(-vel.x, 0.0f);
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Entidades::Entidade::getBody().move(vel.x, 0.0f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Entidades::Entidade::getBody().move(0.0f, -vel.y);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Entidades::Entidade::getBody().move(0.0f, vel.y);
    }
}

void Entidades::Personagens::Jogador::executar()
{

}
