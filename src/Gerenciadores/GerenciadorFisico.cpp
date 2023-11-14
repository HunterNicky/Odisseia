#include "..\..\include\Gerenciadores\GerenciadorFisico.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>

namespace Gerenciadores{
    GerenciadorFisico* GerenciadorFisico::instance = nullptr;

    GerenciadorFisico::GerenciadorFisico():dt(0.0f), alpha(0.0f){}

    GerenciadorFisico::~GerenciadorFisico(){
        delete(instance);
    }

    float GerenciadorFisico::getDeltaTime() const{return dt;}

    GerenciadorFisico* GerenciadorFisico::getInstance(){
        if(instance == nullptr){
            instance = new GerenciadorFisico();
        }
        return instance;
    }

    void GerenciadorFisico::executarFisica(Entidades::Entidade* entidade){
        Entidades::Personagens::Personagem* personagem = static_cast<Entidades::Personagens::Personagem*>(entidade);
        calAcc(personagem);
        calVel(personagem);
    }


    void GerenciadorFisico::calColision(Entidades::Personagens::Personagem* personagem, Entidades::Personagens::Personagem* personagem1){
         sf::Vector2f v1 = personagem->getVel();
        sf::Vector2f v2 = personagem1->getVel();
        float m1 = personagem->getMass();
        float m2 = personagem1->getMass();

        sf::Vector2f newV1 = ((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2);
        sf::Vector2f newV2 = ((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2);

        personagem->setVel(newV1);
        personagem1->setVel(newV2);
    }


    void GerenciadorFisico::update(double dt, double alpha){
        this->dt = dt;
        this->alpha = alpha;
    }

    const sf::Vector2f GerenciadorFisico::calDrag(Entidades::Personagens::Personagem* personagem) const{
        sf::Vector2f test(personagem->getVel().x > 0 ? 1.f : -1.f, personagem->getVel().y > 0 ? 1.f : -1.f);
        sf::Vector2f squareVel
        (personagem->getVel().x * personagem->getVel().x * test.x,
        personagem->getVel().y * personagem->getVel().y * test.y);
        float area = personagem->getSize().x * personagem->getSize().y;
        sf::Vector2f dragForce(area * squareVel.x * 0.1f, area * squareVel.y * 0.1f);
        return (dragForce);
    }

    void GerenciadorFisico::calAcc(Entidades::Personagens::Personagem* personagem){
        sf::Vector2f acc = personagem->getAcc();
        sf::Vector2f forca(0.0f, 9810.f);
        sf::Vector2f dragForce = calDrag(personagem);
        float massa = personagem->getMass();
        
        forca += personagem->getForca();
        forca.x += -dragForce.x;
        forca.y += -dragForce.y;
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
