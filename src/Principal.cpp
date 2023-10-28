#include "..\include\Principal.hpp"
#include <iostream>

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal :: Principal () :
    jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), 1),
    inimigo(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(40.0f, 40.0f), 2, &jogador),
    ObstFacil(sf::Vector2f(200.0f, 300.0f), sf::Vector2f(300.0f, 30.0f), 3),
    gerenciadorDeColisao(&LE),
    gerenciadorFisico(&LE)
{
    LE.push_back(static_cast<Entidades::Entidade*>(&jogador));
    LE.push_back(static_cast<Entidades::Entidade*>(&inimigo));
    LE.push_back(static_cast<Entidades::Entidade*>(&ObstFacil));
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
        gerenciadorFisico.update();
        gerenciadorDeColisao.checkCollision();
        ObstFacil.draw();//mudar
        LE.updateAll();
        LE.drawAll();
        //pGrafico->setViewCenter(personagem.getBody()->getPosition());
        pGrafico->display();
    }
}





