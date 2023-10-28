#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const int id):
            Entidade(pos, size, id)    
        {
            
        }
        Personagem::~Personagem()
        {
        }

        void Personagem::setVel(sf::Vector2f vel)
        {
            this->vel = vel;
        }

        const sf::Vector2f Personagem::getVel() const
        {
            return sf::Vector2f(vel);
        }
    }
}

