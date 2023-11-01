#include "..\..\..\include\Entidades\Obstaculos\Obstaculo.hpp"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const ID id) :
            Entidade(pos, size, id)
        {

        }

        Obstaculo::~Obstaculo(){
            
        }
    }
}