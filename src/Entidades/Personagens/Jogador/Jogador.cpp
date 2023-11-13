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
            Entidade::gFisico->executarFisica(static_cast<Entidades::Entidade*>(this));
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

            void Jogador::pular(){
                if (onFloor) {
                    forca.y = -20000.f;
                    onFloor = false;
                }else{
                    forca.y = 0;
                }
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
            forca.y = -80.f;
            onFloor = false;
        }

            void Jogador::direcionar(bool side){
                if(side){
                    forca.x = 3000.f; 
                }else{
                    forca.x = -3000.f;
                }
                if(!(onFloor)) pular();
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
            void Personagens::Jogador::tratarColisao(Entidade* entidade){
                gFisico->calColision(static_cast<Personagem*>(this), static_cast<Personagem*>(entidade));
                sf::Vector2f aux;
                aux.x = -vel.x;
                aux.y = -vel.y;
                aux.x *= 0.01f;
                aux.y *= 0.01f;
                pos += aux;
            }
    }
}