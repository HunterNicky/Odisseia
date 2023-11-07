#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include <iostream>

namespace Entidades{
    namespace Personagens{
        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Jogador* pJog) :
            Personagem(pos, size, id){
        }

        Inimigo::~Inimigo(){ 
        }

    }
}
