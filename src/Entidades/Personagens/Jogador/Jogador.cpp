#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{

        void Jogador::inicializa()
        {
            Personagem::setVel(sf::Vector2f(0.1f, 0.1f));
        }

        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam, int id):
            Personagem(pos, tam, id)
        {
            inicializa();
        }

        Jogador::~Jogador(){}    

        void Jogador::move()
        {   
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                body.move(-vel.x, 0.0f);
                
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                body.move(vel.x, 0.0f);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                body.move(0.0f, -vel.y);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                body.move(0.0f, vel.y);
            }
        }

        void Jogador::executar()
        {
            move();
        } 
        void Jogador::update(){
            executar();
        }
    }
}