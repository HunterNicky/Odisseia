#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"

 void Entidades::Personagens::Inimigo::inicializa()
 {
    vel = sf::Vector2f(0.03f, 0.03f);
 }

Entidades::Personagens::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, int id, Jogador* pJog) :
    Personagem(pos, size, id)
{
    pJogador = pJog;
    inicializa();
}

Entidades::Personagens::Inimigo::~Inimigo(){
    
}

void Entidades::Personagens::Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
    if(posJogador.x - posInimigo.x > 0.0f)
    {
        body.move(vel.x, 0.0f);
    }
    else
    {
        body.move(-vel.x, 0.0f);
    }
    if(posJogador.y - posInimigo.y > 0.0f)
    {
        body.move(0.0f, vel.y);
    }
    else
    {
        body.move(0.0f, -vel.y);
    }
}

void Entidades::Personagens::Inimigo::move()
{
    sf::Vector2f posJogador = pJogador->getBody().getPosition();
    sf::Vector2f posInimigo = body.getPosition();

    persegueJogador(posJogador, posInimigo);
}
void Entidades::Personagens::Inimigo::executar()
{
}
