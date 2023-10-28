#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"

namespace Entidades {
    namespace Personagens{
        
        void Inimigo::inicializa()
        {
            vel = sf::Vector2f(0.03f, 0.03f);
        }

        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const int id, Jogador* pJog) :
            Personagem(pos, size, id), pJogador(nullptr)
        {
            pJogador = pJog;
            inicializa();
        }

        Inimigo::~Inimigo(){
            
        }

        void Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
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

        void Inimigo::move()
        {
            sf::Vector2f posJogador = pJogador->getBody().getPosition();
            sf::Vector2f posInimigo = body.getPosition();

            persegueJogador(posJogador, posInimigo);
        }
        void Inimigo::executar()
        {
            move();
        }
        void Inimigo::update()
        {
            executar();
        }

    }
}