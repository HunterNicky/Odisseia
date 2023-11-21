#include "..\..\include\Gerenciadores\GerenciadorFisico.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>

namespace Gerenciadores{
    GerenciadorFisico* GerenciadorFisico::instance = nullptr;

    GerenciadorFisico::GerenciadorFisico():dt(0.0f){}

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
        calAcc(entidade);
        calVel(entidade);
    }


    void GerenciadorFisico::calColision(Entidades::Entidade* entidade, Entidades::Entidade* entidade1){
        sf::Vector2f v1 = entidade->getVel();
        sf::Vector2f v2 = entidade1->getVel();
        float m1 = entidade->getMass();
        float m2 = entidade1->getMass();

        sf::Vector2f newV1 = ((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2);
        entidade->setVel(newV1);
    }


    void GerenciadorFisico::update(double dt){this->dt = dt;}

    const sf::Vector2f GerenciadorFisico::calDrag(Entidades::Entidade* entidade) const{
        sf::Vector2f test(entidade->getVel().x > 0 ? 1.f : -1.f, entidade->getVel().y > 0 ? 1.f : -1.f);
        sf::Vector2f squareVel(entidade->getVel().x * entidade->getVel().x * test.x, entidade->getVel().y * entidade->getVel().y * test.y);
        float area = entidade->getSize().x * entidade->getSize().y;
        sf::Vector2f dragForce(area * squareVel.x * 0.1f, area * squareVel.y * 0.1f);
        return (dragForce);
    }

    void GerenciadorFisico::calAcc(Entidades::Entidade* entidade){
        sf::Vector2f acc = entidade->getAcc();
        sf::Vector2f forca(0.0f, 50000.f);
        sf::Vector2f dragForce = calDrag(entidade);
        float massa = entidade->getMass();
        int multi = 1;
        if(entidade->getForca().x == 0 && entidade->getForca().y == 0){
            multi *= 5;
        }
        if(dynamic_cast<Entidades::Personagens::Personagem*>(entidade)){
            
        }
        forca += entidade->getForca();
        forca.x += -dragForce.x * multi;
        forca.y += -dragForce.y;
        acc = forca / massa;
        entidade->setAcc(acc);
    }

    void GerenciadorFisico::calVel(Entidades::Entidade* entidade) {
        sf::Vector2f acc = entidade->getAcc();
        sf::Vector2f position = entidade->getPos();
        sf::Vector2f OldPosition = position;
        position.x += (position.x - entidade->getPrevPos().x) + (acc.x * (dt * dt));
        position.y += (position.y - entidade->getPrevPos().y) + (acc.y * (dt * dt));
        entidade->setPrevPos(OldPosition);
        entidade->setPos(position);
        entidade->setVel(position - OldPosition);
    }
}
