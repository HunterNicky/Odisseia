#include "..\..\..\include\Entidades\Obstaculos\Lava.hpp"
#include "Entidades/Obstaculos/Lava.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <cstdlib>
#include <iostream>

namespace Entidades
{
    namespace Obstaculos{
        Lava::Lava(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Obstaculo(pos, size, id), queimadura(0)
        {
            this->body->setFillColor(sf::Color::Red);
            this->queimadura = 1;
        }
        Lava::~Lava(){}

        void Lava::queimar(Entidade* entidade){
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);   
            pPers->operator--(queimadura);
        }

        void Lava::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    queimar(entidade);
                }
            }
        }

        void Lava::executar(){

        }
        void Lava::update(){
            executar();
        }

        void Lava::salvar(std::ostringstream* entrada){
             (*entrada) << "{ \"ID\": [" << 6 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "] }" << std::endl;
        }
    }
}