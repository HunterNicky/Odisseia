#pragma once

#include "Inimigo.hpp"

namespace Entidades{
    namespace Personagens{
        class InimigoFacil : public Inimigo{
        private:
            int range;

        public:
            InimigoFacil(const sf::Vector2f pos, const sf::Vector2f size, const ID id);
            ~InimigoFacil()

        }
    }
}