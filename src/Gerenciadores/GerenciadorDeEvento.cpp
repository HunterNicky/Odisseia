#include "..\..\include\Gerenciadores\GerenciadorDeEvento.hpp"

namespace Gerenciadores{
    GerenciadorDeEvento* GerenciadorDeEvento::pEvento = nullptr;
    GerenciadorGrafico* GerenciadorDeEvento::pGrafico = GerenciadorGrafico::getInstance();

    GerenciadorDeEvento::GerenciadorDeEvento(){}

    GerenciadorDeEvento::~GerenciadorDeEvento(){
        lObserver.clear();
    }

    GerenciadorDeEvento *GerenciadorDeEvento::getInstance(){
        if(pEvento==nullptr){
            pEvento = new GerenciadorDeEvento();
        }
        return pEvento;
    }

    void GerenciadorDeEvento::addObserver(Observadores::Observer *observer){
        if(observer){
            lObserver.push_back(observer);
        }
    }

    void GerenciadorDeEvento::removeObserver(Observadores::Observer *observer){
        if(observer){
            lObserver.remove(observer);
        }
    }

    void GerenciadorDeEvento::stage(){
        sf::Event event;
        while(pGrafico->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGrafico->close();
            }else if(event.type == sf::Event::KeyPressed){
                for(auto obs : lObserver){
                    obs->notifyPressed(obs->getKeyString(event.key.code));
                }
            }else if(event.type == sf::Event::KeyReleased){
                for(auto obs : lObserver){
                    obs->notifyReleased(obs->getKeyString(event.key.code));
                }
            }

        }
    }

}

