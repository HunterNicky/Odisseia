#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Entidade(pos, size, id){
        }
        Personagem::~Personagem()
        {
        }

        void Personagem::verificaSolo(const sf::Vector2f mtv){
            if(mtv.y < 0.f){
                onFloor = true;
            }else{onFloor = false;}     
        }
        
        void Personagem::setOnFloor(const bool floor){this->onFloor = floor;}

        const int Personagem::getNum_vidas() const{return num_vidas;}

        void Personagem::move(){
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }
    }
}

