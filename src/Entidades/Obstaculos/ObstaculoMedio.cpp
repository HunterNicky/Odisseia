#include "..\..\..\include\Entidades\Obstaculos\ObstaculoMedio.hpp"

namespace Entidades{
    namespace Obstaculos{
        ObstaculoMedio::ObstaculoMedio(const sf::Vector2f pos, const sf::Vector2f size, const ID id):
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Green);
        }
        ObstaculoMedio::~ObstaculoMedio(){}
        
        void ObstaculoMedio::executar(){
            
        }
        void ObstaculoMedio::update(){
            executar();
        }
    }
}