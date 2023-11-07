#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        void Jogador::inicializa(){
            vel = sf::Vector2f(0.1f, 0.1f);
            body->setFillColor(sf::Color::Blue);
            num_vidas = 1000;
        }

        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Personagem(pos, size, id)
        {
            inicializa();
        }

        Jogador::~Jogador(){}   

        void Jogador::operator--(){
            num_vidas--;
        }

        void Jogador::move(){   
            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Jogador::neutralizarInimigo(Entidade* pInimigo){
            if(pInimigo){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(pInimigo);
                    pPers->operator--();
                    //deletar personagem
                }
            }
        }

        void Jogador::tratarColisao(Entidade* entidade){
            switch (entidade->getId())
            {
            case (ID::Inimigo):
                neutralizarInimigo(entidade);
                break;
            case (ID::Plataforma):
                break;
            default:
                break;
            }
        }
        void Jogador::executar(){
            bool KeyPressed = false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                forca = sf::Vector2f(-10.f, 0.f); 
                KeyPressed = true;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                forca = sf::Vector2f(10.f, 0.f); 
                KeyPressed = true;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                forca += sf::Vector2f(0.f, -100.f);
                KeyPressed = true;
            }

            if(!KeyPressed){
                forca *= 0.f;
            }
            move();
        } 

        void Jogador::update(){
            executar();
        }
    }
}