#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Entidade(pos, size, id),
            massa(20)    
        {
            
            jumpTimer.restart();
        }
        Personagem::~Personagem()
        {
        }

        void Personagem::verificaSolo(const sf::Vector2f mtv){
            if(mtv.y < 0.f){
                onFloor = true;
                jumpTimer.restart();
            }else{onFloor = false;}     
        }

        void Personagem::setVel(sf::Vector2f vel){this->vel = vel;}

        void Personagem::setAcc(sf::Vector2f acc) { this->acc = acc; }

        void Personagem::setForca(sf::Vector2f forca){this->forca = forca;}

        void Personagem::setMassa(float massa){this->massa = massa;}

        const sf::Vector2f Personagem::getVel() const { return vel; }

        void Personagem::setOnFloor(bool floor){this->onFloor = floor;}

        const sf::Vector2f Personagem::getAcc() const{return acc;}

        const sf::Vector2f Personagem::getForca() const{return forca;}

        const float Personagem::getMass() const{return massa;}

        const int Personagem::getNum_vidas() const{return num_vidas;}

        void Personagem::move(){
            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }
    }
}

