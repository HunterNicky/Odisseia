#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"

namespace Entidades{
    namespace Personagens{
        void Inimigo::inicializa(){
            vel = sf::Vector2f(0.03f, 0.03f);
            this->getBody()->setFillColor(sf::Color::Red);
        }

        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const ID id, Jogador* pJog) :
            Personagem(pos, size, id){
            pJogador = pJog;
            inicializa();
            srand(time(NULL));
            moveAleatorio = rand()%4;
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
        void Inimigo::movimentoAleatorio(){

            if(moveAleatorio == 0){
                forca.x = 4.0f;
            }else if(moveAleatorio == 1){
                forca.x = -4.0f;
            }else if(moveAleatorio == 2){
                forca.y = 4.0f;
            }else{
                forca.y = -4.0f;
            }
        }

        void Inimigo::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = body->getPosition();

            if((fabs(posJogador.x - posInimigo.x) <= RAIO_PERS_X) && (fabs(posJogador.y - posInimigo.y) <= RAIO_PERS_Y))
            {
                persegueJogador(posJogador, posInimigo);
            }
            else{
                movimentoAleatorio();
            }

            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Inimigo::executar(){
            move();
        }

        void Inimigo::update(){
            executar();
        }

    }
}
