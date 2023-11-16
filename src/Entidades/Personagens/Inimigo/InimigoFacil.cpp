#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoFacil.hpp"
#include <stdlib.h>

namespace Entidades{
    namespace Personagens{
        void InimigoFacil::inicializa(){
            vel = sf::Vector2f(0.1f, 0.1f);
            body->setFillColor(sf::Color::Red);
            range = 200;
            num_vidas = 10;
            srand(time(NULL));
            moveAleatorio = rand()%4;
            raivosidade = rand()%10;
        }

        InimigoFacil::InimigoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(pos, size, id, pJog){
            inicializa();
            if((raivosidade >= 0) && (raivosidade < 3)){//30% chance de ser raivoso
                dano = 20;
            }else{
                dano = 10;
            }

        }
        InimigoFacil::~InimigoFacil(){

        }

        void InimigoFacil::operator--(const int dano){
            num_vidas-=dano;
        }

        void InimigoFacil::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo){
            if(posJogador.x - posInimigo.x > 0.0f){
                forca.x = 3000.f;
            }else{
                forca.x = -3000.f;
            }

            if(posJogador.y - posInimigo.y > 0.0f){
                forca.y = 30000.f;
            }else{
                forca.y = -30000.f;
            }
        }

        void InimigoFacil::movimentoAleatorio(){

            if(moveAleatorio == 0){
                forca.x = 3000.0f;
            }else if(moveAleatorio == 1){
                forca.x = -3000.0f;
            }else if(moveAleatorio == 2){
                forca.y = 3000.0f;
            }else{
                forca.y = -3000.0f;
            }
        }

        void InimigoFacil::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = body->getPosition();

            if((fabs(posJogador.x - posInimigo.x) <= (float)range) && (fabs(posJogador.y - posInimigo.y) <= (float)range))
            {
                persegueJogador(posJogador, posInimigo);
            }
            else{
                movimentoAleatorio();
            }
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void InimigoFacil::danificar(Entidade* entidade){
            if(entidade){
                Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
                pPers->operator--(1);
            }
        }

        void InimigoFacil::tratarColisao(Entidade* entidade){
            if(entidade->getId() == Entidades::ID::jogador){
                danificar(entidade);
            }
        }

        void InimigoFacil::executar(){
            move();
        }

        void InimigoFacil::update(){
            executar();
        }
    }
}