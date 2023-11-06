#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoFacil.hpp"


namespace Entidades{
    namespace Personagens{
        InimigoFacil::InimigoFacil(const sf::Vector2f pos, const sf::Vector2f size, const ID id):
            Inimigo(pos, size, id, nullptr){

        }
        InimigoFacil::~InimigoFacil(){

        }
    }
}