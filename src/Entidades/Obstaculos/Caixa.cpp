#include "..\..\..\include\Entidades\Obstaculos\Caixa.hpp"

namespace Entidades{
    namespace Obstaculos{
        ObstaculoFacil::ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id) :
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::White);
        }
        ObstaculoFacil::~ObstaculoFacil(){

        }
        void ObstaculoFacil::tratarColisao()
        {
            
        }
        void ObstaculoFacil::executar(){
            
        }
        void ObstaculoFacil::update(){
            executar();
        }
    }
}
