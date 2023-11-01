#include "..\..\..\include\Entidades\Obstaculos\ObstaculoFacil.hpp"

namespace Entidades{
    namespace Obstaculos{
        ObstaculoFacil::ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f size, const ID id) :
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Cyan);
        }
        ObstaculoFacil::~ObstaculoFacil(){

        }
        void ObstaculoFacil::executar(){
            
        }
        void ObstaculoFacil::update(){
            executar();
        }
    }
}