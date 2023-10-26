#include "..\include\Principal.hpp"
#include <iostream>

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal :: Principal () :
    jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), 1),
    inimigo(sf::Vector2f(40.0f, 40.0f), sf::Vector2f(40.0f, 40.0f), 2, &jogador)
{
    executar();
}

Principal :: ~Principal(){

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
        jogador.move();
        inimigo.move();
        pGrafico->draw(jogador.getBody());
        pGrafico->draw(inimigo.getBody());
        pGrafico->display();
    }
}





