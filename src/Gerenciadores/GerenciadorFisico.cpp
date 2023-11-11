#include "..\..\include\Gerenciadores\GerenciadorFisico.hpp"
#include <iostream>
#include <math.h>

namespace Gerenciadores {
    GerenciadorFisico::GerenciadorFisico(Lista::ListaDeEntidades* listaEntidades): 
    LE(listaEntidades), dt(0.0f), alpha(0.0f){}

    GerenciadorFisico::~GerenciadorFisico(){}

    float GerenciadorFisico::getDeltaTime()const{return dt;}

    void GerenciadorFisico::update(double dt, double alpha){
        this->dt = dt;
        this->alpha = alpha;
        Lista::ListaDeEntidades* listaEntidades = LE;
        for(unsigned int i = 0; i < listaEntidades->getSize(); i++){
            Entidades::Entidade* entidade = (*listaEntidades)[i];
            if(entidade->getId() == 1 || entidade->getId() == 2){
                Entidades::Personagens::Personagem* personagem = dynamic_cast<Entidades::Personagens::Personagem*>(entidade);
                calAcc(personagem);
                calVel(personagem);
            }
        }
    }

    void GerenciadorFisico::calAcc(Entidades::Personagens::Personagem* personagem){
        sf::Vector2f acc = personagem->getAcc();
        float massa = personagem->getMass();
        sf::Vector2f forca(0.0f, 2.f);
        forca = (forca*massa) + personagem->getForca();
        acc = forca / massa;
        personagem->setAcc(acc);
    }

    void GerenciadorFisico::calVel(Entidades::Personagens::Personagem* personagem){
        sf::Vector2f vel = personagem->getVel();
        sf::Vector2f acc = personagem->getAcc();
        
        float velocidadeMaxima = 0.5f;

        if(abs(acc.x) < 0.01f && abs(acc.y) < 0.01f){
            vel.x *= 0.999f;
            vel.y *= 0.999f;
        }else{
            vel.x += acc.x * dt * alpha;
            vel.y += acc.y * dt * alpha;
        }
        float velocidadeAtual = std::sqrt(vel.x * vel.x + vel.y * vel.y);
        if(velocidadeAtual > velocidadeMaxima){
            vel.x = (vel.x / velocidadeAtual) * velocidadeMaxima;
            vel.y = (vel.y / velocidadeAtual) * velocidadeMaxima;
        }
        personagem->setVel(vel);
    }
}
