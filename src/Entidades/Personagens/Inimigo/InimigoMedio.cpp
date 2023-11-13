#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoMedio.hpp"

namespace Entidades{
    namespace Personagens{
        void InimigoMedio::inicializa(){
            vel = sf::Vector2f(0.01f, 0.01f);
            body->setFillColor(sf::Color::Magenta);
            dano = 5;
            srand(time(NULL));
            moveAleatorio = (int)rand()%2;
            num_vidas = 100;
        }
        InimigoMedio::InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Estados::Fases::Fase* pFase):   
            Inimigo(pos, size, id, pJog), pFase(pFase){
            nivel_maldade = (int)rand()%2;
            inicializa();
        }

        InimigoMedio::~InimigoMedio(){}

        void InimigoMedio::operator--(const int dano){
            num_vidas-=dano;
        }

        void InimigoMedio::movimentoAleatorio(){
            if(moveAleatorio == 0){
                forca.x = 4.0f;
            }else{
                forca.x = -4.0f;
            }
        }

        void InimigoMedio::atirarProjetil(sf::Vector2f pos, const bool direita){
            pFase->newProjetil(pos, direita);
        }

        void InimigoMedio::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = getBody()->getPosition();
            bool direita;
            
            if(fabs(posJogador.x - posInimigo.x) < RANGE){
                forca.x = 0.0f;
                if(posJogador.x > posInimigo.x){
                    direita = true;
                }else{
                    direita = false;
                }
                atirarProjetil(posInimigo, direita);
            }
            else{
                movimentoAleatorio();
            }

            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void InimigoMedio::danificar(Entidade *entidade){
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(dano);
        }

        void InimigoMedio::tratarColisao(Entidade *entidade){
            if(entidade->getId() == Entidades::ID::jogador){
                danificar(entidade);
            }
        }

        void InimigoMedio::executar(){
            move();
        }

        void InimigoMedio::update(){
            executar();
        }
    }
}