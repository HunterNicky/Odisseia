#include "..\include\Principal.hpp"
#include <iostream>

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal::Principal () :
    jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), 1)
{
    LE.push_back(static_cast<Entidades::Entidade*>(&jogador));
    //LE.push_back(static_cast<Entidades::Entidade*>(&inimigo));
    executar();
}

Principal::~Principal(){
}

void Principal::executar(){

    while(pGrafico->isWindowOpen())
    {
        
        sf::Event evento;
        if(pGrafico->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
            {
                pGrafico->close();
            }
            else if(evento.type == sf::Event::KeyPressed)
            {
                if(evento.key.code == sf::Keyboard::Escape)
                {
                    pGrafico->close();
                }
            }
        }
        pGrafico->clear();
        LE.updateAll();
        LE.drawAll();
        pGrafico->display();
    }
}





