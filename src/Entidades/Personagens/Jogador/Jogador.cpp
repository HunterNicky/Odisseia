#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        void Jogador::inicializa(){
            vel = sf::Vector2f(0.1f, 0.1f);
            body->setFillColor(sf::Color::Blue);
        }

        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, int id):
            Personagem(pos, size, id){
            inicializa();
        }

        Jogador::~Jogador(){}   

        void Jogador::move(){   
            Entidade::body->move(vel);
        }

        void Jogador::executar(){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                forca = sf::Vector2f(-5.f, 0.f); 
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                forca = sf::Vector2f(5.f, 0.f); 
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                forca = sf::Vector2f(0.f, -5.f); 
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                forca = sf::Vector2f(0.f, 5.f); 
            }else{
                forca *= 0.f;
            }
            move();
        } 

        void Jogador::update(){
            executar();
        }
    }
}