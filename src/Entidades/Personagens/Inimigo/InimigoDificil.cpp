#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoDificil.hpp"

namespace Entidades{
    namespace Personagens{
        void InimigoDificil::inicializa(){
            vel = sf::Vector2f(0.01f, 0.01f);
            num_vidas = 1000;
            body->setFillColor(sf::Color::Yellow);
        }

        InimigoDificil::InimigoDificil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(pos, size, id, pJog){
            inicializa();
        }

        InimigoDificil::~InimigoDificil(){

        }
        void InimigoDificil::operator--(const int dano){
            num_vidas-=dano;
        }
        void InimigoDificil::movimentoAleatorio(){

        }
        void InimigoDificil::move(){
            Entidade::body->setPosition(pos);
            gColisao->Notify(static_cast<Entidades::Entidade*>(this));
        }

        void InimigoDificil::danificar(Entidade* entidade){
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(200);
        }

        void InimigoDificil::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    danificar(entidade);
                }
            }
        }
        void InimigoDificil::executar(){
            move();
        }
        void InimigoDificil::update(){
            executar();
        }
    }
}