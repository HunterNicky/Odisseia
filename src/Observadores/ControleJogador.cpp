#include "..\..\include\Observadores\ControleJogador.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleJogador::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleJogador::ControleJogador(Entidades::Personagens::Jogador *pJogador):
    Observer(),
    pJogador(pJogador),
    pular("W"), esquerda("A"), direita("D"), fechar("Escape"){
    }

    ControleJogador::~ControleJogador(){
    }

    void ControleJogador::setJogador(Entidades::Personagens::Jogador *pJogador){
        this->pJogador = pJogador;
    }
    void ControleJogador::notifyPressed(std::string key){
        if(pJogador){
            if(key == direita){
                pJogador->direcionar(true);
            }else if(key == esquerda){
                pJogador->direcionar(false);
            }
            if(key == pular){
                pJogador->pular();
            }
            if(key == fechar){
                pMaquinaDeEstado->popEstado();
            }
        }
    }

    void ControleJogador::notifyReleased(std::string key){
        if(pJogador){
            if(key == direita){
                pJogador->parar();
            }else if(key == esquerda){
                pJogador->parar();
            }else if(key == pular){
                pJogador->setOnFloor(false);
                pJogador->pular();
            }
        }
    }

}
