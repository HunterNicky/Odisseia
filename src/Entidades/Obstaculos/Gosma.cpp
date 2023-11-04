#include "..\..\..\include\Entidades\Obstaculos\Gosma.hpp"

namespace Entidades{
    namespace Obstaculos{
        Gosma::Gosma(const sf::Vector2f pos, const sf::Vector2f size, const ID id):
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Green);
        }
        Gosma::~Gosma(){}
        
        void Gosma::executar(){

        }
        void Gosma::update(){
            executar();
        }
    }
}