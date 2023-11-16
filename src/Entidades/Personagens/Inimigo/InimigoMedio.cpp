#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoMedio.hpp"
//#include "Entidades/Entidade.hpp"
//#include "Entidades/Personagens/Inimigo/InimigoMedio.hpp"
#include "Estados/Fases//Fase.hpp"

namespace Entidades{
    namespace Personagens{
        void InimigoMedio::inicializa(){
            vel = sf::Vector2f(0.01f, 0.01f);
            body->setFillColor(sf::Color::Magenta);
            srand(time(NULL));
            moveAleatorio = (int)rand()%2;
            num_vidas = 100;
            ProjAtivo = false;
        }
        InimigoMedio::InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Estados::Fases::Fase* pFase):   
            Inimigo(pos, size, id, pJog), pFase(nullptr){
            nivel_maldade = (int)rand()%2;
            inicializa();
            this->pFase = pFase;
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
            ProjAtivo = true;
            pFase->newProjetil(pos, direita);
        }

        void InimigoMedio::deletarProjetil(){
            ProjAtivo = false;
            //pFase->deleteProjetil();
        }

        void InimigoMedio::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = getBody()->getPosition();
            bool direita;
            
            if((fabs(posJogador.x - posInimigo.x) < RANGE) && (!ProjAtivo)){
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
            Entidade::gFisico->executarFisica(static_cast<Entidades::Entidade*>(this));
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void InimigoMedio::tratarColisao(Entidade *entidade){
  
        }

        void InimigoMedio::executar(){
            move();
        }

        void InimigoMedio::update(){
            executar();
        }
    }
}