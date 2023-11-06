#pragma once
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\Entidades\Entidade.hpp"

namespace Entidades{
    class Entidade;
}

namespace Lista{
    class ListaDeEntidades;
}

namespace Gerenciadores{
    class Mediator{
        public:
            virtual void setList(Lista::ListaDeEntidades* LE) = 0;
            virtual void Notify(Entidades::Entidade* entidade, const sf::Vector2f mtv) const = 0;
    };

}