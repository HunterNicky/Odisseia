#include "..\..\include\Gerenciadores\GerenciadorFisico.hpp"
#include <iostream>
#include <math.h>

namespace Gerenciadores{
    GerenciadorFisico::GerenciadorFisico(Lista::ListaDeEntidades* listaEntidades) :
        LE(listaEntidades), dt(0.0f), alpha(0.0f){}

    GerenciadorFisico::~GerenciadorFisico(){}

    float GerenciadorFisico::getDeltaTime() const{ return dt; }

    void GerenciadorFisico::update(double dt, double alpha) {
        this->dt = dt;
        this->alpha = alpha;
        Lista::ListaDeEntidades* listaEntidades = LE;

        for (unsigned int i = 0; i < listaEntidades->getSize(); i++) {
            Entidades::Entidade* entidade = (*listaEntidades)[i];
            if (entidade->getId() == 1 || entidade->getId() == 2) {
                Entidades::Personagens::Personagem* personagem = dynamic_cast<Entidades::Personagens::Personagem*>(entidade);
                calAcc(personagem);
                calVel(personagem);
            }
        }
    }

    void GerenciadorFisico::calAcc(Entidades::Personagens::Personagem* personagem){
        sf::Vector2f acc = personagem->getAcc();
        float massa = personagem->getMass();
        sf::Vector2f forca(0.0f, 9810.f);
        forca += personagem->getForca();
        acc = forca / massa;
        personagem->setAcc(acc);
    }

    void GerenciadorFisico::calVel(Entidades::Personagens::Personagem* personagem) {
        sf::Vector2f acc = personagem->getAcc();
        sf::Vector2f position = personagem->getPos();
        sf::Vector2f OldPosition = position;
        position.x += (position.x - personagem->getPrevPos().x) + (acc.x * (dt * dt) * alpha);
        position.y += (position.y - personagem->getPrevPos().y) + (acc.y * (dt * dt) * alpha);
        personagem->setPrevPos(OldPosition);
        personagem->setPos(position);

        personagem->setVel(position - OldPosition);
    }
}
