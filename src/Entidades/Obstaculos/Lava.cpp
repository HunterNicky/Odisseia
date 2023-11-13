#include "..\..\..\include\Entidades\Obstaculos\Lava.hpp"
#include <iostream>

namespace Entidades
{
    namespace Obstaculos{
        Lava::Lava(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Obstaculo(pos, size, id)
        {
            this->body->setFillColor(sf::Color::Red);
        }
        Lava::~Lava(){}

        void Lava::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    //Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
                   //pPers->operator--(2);
                }
            }
        }

        void Lava::executar(){
            if(danoso)
            {
                std::cout << "Dano" << std::endl;
            }
        }
        void Lava::update(){
            executar();
        }
    }
}