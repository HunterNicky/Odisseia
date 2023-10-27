#pragma once
#include "Gerenciadores\GerenciadorGrafico.hpp"

class Ente{
    protected:
        static Gerenciadores::GerenciadorGrafico* pGrafico;
        sf::Vector2f pos;
        sf::Vector2f size;
    public:
        Ente(sf::Vector2f pos, sf::Vector2f size);
        virtual ~Ente();
        sf::Vector2f getPos();
        sf::Vector2f getSize();
        void setPos(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void executar() = 0;
};