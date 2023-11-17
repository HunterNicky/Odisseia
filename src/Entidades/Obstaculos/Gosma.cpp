#include "..\..\..\include\Entidades\Obstaculos\Gosma.hpp"
#include "Entidades/Entidade.hpp"

namespace Entidades{
    namespace Obstaculos{
        Gosma::Gosma(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Green);
        }
        Gosma::~Gosma(){}

        void Gosma::atrasar(Entidade* entidade){
            sf::Vector2f vel = entidade->getVel()/2.0f;
            entidade->setVel(vel);
        }

        void Gosma::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    atrasar(entidade);
                }
            }
        }
        
        void Gosma::executar(){

        }
        void Gosma::update(){
            executar();
        }
    }
}