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

        void Jogador::operator--(const int dano){
            std::cout << num_vidas << std::endl;
            num_vidas-=dano;
        }

        void Jogador::move(){   
            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Jogador::neutralizarInimigo(Entidade* pInimigo){
            if(pInimigo){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(pInimigo);
                    pPers->operator--(2);
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
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Caixa):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Gosma):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Lava):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            default:
                break;
            }
        }

        void Jogador::pular(){
            if (jumpTimer.getElapsedTime().asSeconds() < 0.002f && onFloor) {
                forca.y = -80.f;
                onFloor = false;
            }else{
                forca.y = 0;
            }
        }

        void Jogador::direcionar(bool side){
            if(side){
                forca.x = 100.f; 
            }else{
                forca.x = -100.f;
            }
            if(!(jumpTimer.getElapsedTime().asSeconds() < 0.002f && onFloor)) pular();
        }

        void Jogador::parar(){
            forca.x = 0;
        }

        void Jogador::executar(){
            move();
        }        
        void Jogador::update(){
            executar();
        }
    }
}