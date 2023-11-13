#include "..\..\..\include\Entidades\Obstaculos\Gosma.hpp"

namespace Entidades{
    namespace Obstaculos{
        Gosma::Gosma(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Green);
        }
        Gosma::~Gosma(){}

        void Gosma::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
                    sf::Vector2f vel = pPers->getVel();
                    //sf::Vector2f fcc = sf::Vector2f(vel.x*18.0f, vel.y*18.0f);
                    //pPers->setForca(pPers->getForca() - fcc);
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