#pragma once

#include <SFML/Graphics.hpp>
#include "..\Lista\ListaDeEntidades.hpp"

namespace Gerenciadores{
    class GerenciadorDeColisao{
    private:
        Lista::ListaDeEntidades* LE;
    public:
        GerenciadorDeColisao(Lista::ListaDeEntidades* LE);
        ~GerenciadorDeColisao();
        bool collisionDetection(const sf::Drawable* drawable1, const sf::Drawable* drawable2, sf::Vector2f *mtv = nullptr);
        void checkCollision();
    };
    
}