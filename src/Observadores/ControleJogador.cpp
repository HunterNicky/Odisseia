#include "..\..\include\Observadores\ControleJogador.hpp"

namespace Observadores{
    ControleJogador::ControleJogador(Entidades::Personagens::Jogador *pJogador):
    Observer(),
    pJogador(pJogador),
    pular("W"), esquerda("A"), direita("D"){
        keyPressed.insert(std::pair<std::string, bool>(direita, false));
        keyPressed.insert(std::pair<std::string, bool>(esquerda, false));
        keyPressed.insert(std::pair<std::string, bool>(pular, false));
    }

    ControleJogador::~ControleJogador(){
        keyPressed.clear();
    }

    void ControleJogador::setJogador(Entidades::Personagens::Jogador *pJogador){
        this->pJogador = pJogador;
    }
    void ControleJogador::notifyPressed(std::string key){
        
        if(pJogador){
            if(key == direita){
                keyPressed[direita] = true;
                pJogador->direcionar(true);
            }else if(key == esquerda){
                keyPressed[esquerda] = true;
                pJogador->direcionar(false);
            }
            if(key == pular){
                keyPressed[pular] = true;
                pJogador->pular();
            }
        }
    }

    void ControleJogador::notifyReleased(std::string key){
        
        if(pJogador){
            if(key == direita){
                keyPressed[direita] = false;
                pJogador->parar();
            }else if(key == esquerda){
                keyPressed[esquerda] = false;
                pJogador->parar();
            }else if(key == pular){
                keyPressed[pular] = false;
                pJogador->setOnFloor(false);
                pJogador->pular();
            }
        }
    }

}
