#pragma once

#include <SFML/Graphics.hpp>
#include "..\Lista\ListaDeEntidades.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/QuadTree.hpp"
#include "QuadTree.hpp"
#include "Mediator.hpp"

namespace Gerenciadores{
    class GerenciadorDeColisao : public Mediator{
    private:
        static GerenciadorDeColisao* instance;
        Lista::ListaDeEntidades* LE;
        Quadtree quadTree;
        GerenciadorDeColisao();
    public:
        virtual ~GerenciadorDeColisao();
        static GerenciadorDeColisao* getInstance();
        void setList(Lista::ListaDeEntidades* LE) override;
        void Notify(Entidades::Entidade* entidade, Entidades::Entidade* entidade2, const sf::Vector2f mtv) const override;
        void atualizarQuadTree();
        void checkCollision(Entidades::Entidade *entidade);
    };
    
}