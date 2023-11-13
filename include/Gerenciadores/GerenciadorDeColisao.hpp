#pragma once

#include <SFML/Graphics.hpp>
#include "Entidades/Entidade.hpp"
#include "Mediator.hpp"
namespace Gerenciadores{
    class GerenciadorDeColisao : public Mediator{
    private:
        static GerenciadorDeColisao* instance;
        Lista::ListaDeEntidades* LE;
        GerenciadorDeColisao();
    public:
        virtual ~GerenciadorDeColisao();
        static GerenciadorDeColisao* getInstance();
        void setList(Lista::ListaDeEntidades* LE) override;
        void Notify(Entidades::Entidade* entidade, Entidades::Entidade* entidade2, const sf::Vector2f mtv) const override;
        void checkCollision(Entidades::Entidade* entidade);
        bool collisionDetection(const sf::Drawable* drawable1, const sf::Drawable* drawable2, sf::Vector2f *mtv = nullptr);
    };
    
}