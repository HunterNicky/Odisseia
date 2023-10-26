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
            //Entidade::setBody(sf::RectangleShape(tam));
            //Entidade::getBody().setPosition(pos);
            Entidade::getBody().setFillColor(sf::Color::Green);
            inicializa();
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::move()
        {
            sf::Vector2f vel = Personagem::getVel();
            sf::Vector2f position = Entidade::getPos();
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                position.x -= vel.x;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                position.x += vel.x;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                position.y -= vel.y;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                position.y += vel.y;
            }
            cout << Entidade::getPos().x << "|" << Entidade::getPos().y << endl;
            Entidade::setPos(position);
        }

        void Jogador::executar(){
            move();
        }

        void Jogador::update(){
            executar();
        }
    }
}