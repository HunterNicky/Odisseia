#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"

namespace Entidades{
    namespace Personagens{
        void Inimigo::inicializa(){
            vel = sf::Vector2f(0.03f, 0.03f);
            this->getBody()->setFillColor(sf::Color::Red);
        }

        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, int id, Jogador* pJog) :
            Personagem(pos, size, id){
            pJogador = pJog;
            inicializa();
        }

        Inimigo::~Inimigo(){ 
        }

        void Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo){
            if(posJogador.x - posInimigo.x > 0.0f){
                forca.x = 8.f;
            }else{
                forca.x = -8.f;
            }

            if(posJogador.y - posInimigo.y > 0.0f){
                forca.y = 80.f;
            }else{
                forca.y = -80.f;
            }
        }

        void Inimigo::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = body->getPosition();

            persegueJogador(posJogador, posInimigo);

            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Inimigo::executar(){
            move();
        }

        void Inimigo::update(){
            executar();
        }

        void Inimigo::tratarColisao()
        {
        }
    }

}
