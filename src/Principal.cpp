#include "..\include\Principal.hpp"
#include <iostream>

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal :: Principal () :
    jogador(sf::Vector2f(250.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), Entidades::jogador),
    inimigo(sf::Vector2f(150.0f, 200.0f), sf::Vector2f(40.0f, 40.0f), Entidades::Inimigo, &jogador),
    ObstFacil(sf::Vector2f(0.0f, 300.0f), sf::Vector2f(3000.0f, 80.0f), Entidades::ObstaculoFacil),
    ObstFacil1(sf::Vector2f(200.0f, 100.0f), sf::Vector2f(800.0f, 50.0f), Entidades::ObstaculoFacil), 
    gerenciadorDeColisao(&LE),
    gerenciadorFisico(&LE)
{
    LE.push_back(static_cast<Entidades::Entidade*>(&jogador));
    LE.push_back(static_cast<Entidades::Entidade*>(&inimigo));
    LE.push_back(static_cast<Entidades::Entidade*>(&ObstFacil));
    LE.push_back(static_cast<Entidades::Entidade*>(&ObstFacil1));

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
        LE.updateAll();
        LE.drawAll();
        pGrafico->setViewCenter(jogador.getBody()->getPosition());
        pGrafico->display();
    }
}





