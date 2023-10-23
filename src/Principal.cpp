#include "..\include\Principal.hpp"

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal :: Principal () :
    jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f))
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
        pGrafico->draw(jogador.getCorpo());
        pGrafico->display();

    }
}





