#pragma once

#include <SFML\Graphics.hpp>
#include "Gerenciadores\GerenciadorGrafico.hpp"

class Ente{
    protected:
        static Gerenciadores::GerenciadorGrafico* pGrafico;
        sf::Vector2f pos;
        sf::Vector2f size;
    public:
        Ente(const sf::Vector2f pos, const sf::Vector2f size);
        Ente();
        virtual ~Ente();
        sf::Vector2f getPos();
        sf::Vector2f getSize();
        void setPos(const sf::Vector2f pos);
        void setSize(const sf::Vector2f size);
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void executar() = 0;
};