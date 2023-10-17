#include "..\include\Jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) :
    corpo(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
    corpo.setFillColor(sf::Color::Red);
    inicializa();
}

Jogador::Jogador(const sf::RectangleShape corpo):
    corpo(corpo)
{
    inicializa();
}

Jogador::Jogador():
    corpo()
{
    inicializa();
}
void Jogador::inicializa()
{
    vel = sf::Vector2f(0.1f,0.1f);
}
Jogador::~Jogador()
{
}

const sf::RectangleShape Jogador::getCorpo()
{
    return corpo;
}

void Jogador::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        corpo.move(-vel.x, 0.0f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        corpo.move(vel.x, 0.0f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        corpo.move(0.0f, -vel.y);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        corpo.move(0.0f, vel.y);
    }
}
