#pragma once

#include <SFML/Graphics.hpp>
#include "..\Lista\ListaDeEntidades.hpp"

namespace Gerenciadores{
    class GerenciadorDeColisao{
    private:
        Lista::ListaDeEntidades* LE;
    public:
        GerenciadorDeColisao();
        ~GerenciadorDeColisao();
        void setList(Lista::ListaDeEntidades* LE) override;
        void Notify(Entidades::Entidade* entidade, const sf::Vector2f mtv) const override;
        void checkCollision(Entidades::Entidade* entidade);
        bool collisionDetection(const sf::Drawable* drawable1, const sf::Drawable* drawable2, sf::Vector2f *mtv = nullptr);
    };
    
}