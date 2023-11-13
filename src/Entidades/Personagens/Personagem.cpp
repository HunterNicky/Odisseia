#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{

        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, int id):
            Entidade(pos, size, id),
            prevPos(pos),    
            massa(20){
        }
        Personagem::~Personagem()
        {
        }

        void Personagem::setVel(sf::Vector2f vel){this->vel = vel;}

        void Personagem::verificaSolo(const sf::Vector2f mtv){
            if(mtv.y < 0.f){
                onFloor = true;
            }else{onFloor = false;}     
        }
        void Personagem::setAcc(sf::Vector2f acc) { this->acc = acc;}

        void Personagem::setMassa(float massa){this->massa = massa;}

        const sf::Vector2f Personagem::getVel() const { return vel;}

        void Personagem::setOnFloor(bool floor){this->onFloor = floor;}

        const sf::Vector2f Personagem::getAcc() const{return acc;}

        const sf::Vector2f Personagem::getForca() const{return forca;}

        const float Personagem::getMass() const{return massa;}

        void Personagem::setPrevPos(sf::Vector2f prevPos){this->prevPos = prevPos;}

        const sf::Vector2f Personagem::getPrevPos() const{return prevPos;}

        void Personagem::move(){
            Entidade::body->setPosition(pos);
            Entidade::gFisico->executarFisica(static_cast<Entidades::Entidade*>(this));
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }
    }
}

