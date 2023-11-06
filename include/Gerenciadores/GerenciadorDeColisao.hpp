#pragma once

#include <SFML/Graphics.hpp>
#include "..\Lista\ListaDeEntidades.hpp"
#include "Mediator.hpp"

namespace Gerenciadores{
    class GerenciadorDeColisao: public Mediator{
    private:
        Lista::ListaDeEntidades* LE;
    public:
        GerenciadorDeColisao(Lista::ListaDeEntidades* LE);
        ~GerenciadorDeColisao();
        void setList(Lista::ListaDeEntidades* LE);
        void Notify(Entidades::Entidade* entidade, const sf::Vector2f mtv) const;
        bool collisionDetection(const sf::Drawable* drawable1, const sf::Drawable* drawable2, sf::Vector2f *mtv = nullptr);
        void checkCollision();
    };
    
}