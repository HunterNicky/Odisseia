#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoMedio.hpp"
#include "Entidades/Personagens/Inimigo/InimigoMedio.hpp"
#include <sstream>

namespace Entidades{
    namespace Personagens{
        void InimigoMedio::inicializa(){
            vel = sf::Vector2f(0.0f, 0.0f);
            body->setFillColor(sf::Color::Magenta);
            srand(time(NULL));
            moveAleatorio = (int)rand()%2;
            num_vidas = 100;
            ProjAtivo = false;
        }
        InimigoMedio::InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Fases::Fase* pFase):   
            Inimigo(pos, size, id, pJog) {
            nivel_maldade = (int)rand()%2;
            inicializa();
            this->pFase = pFase;
        }

        InimigoMedio::InimigoMedio(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_INIMIGO_MED_X, TAM_INIMIGO_MED_Y), id, pJog)
        {
            this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
            body->setFillColor(sf::Color::Magenta);
            this->num_vidas = atributos[pos]["Vida"][0];
            int ativo = atributos[pos]["Ativo"][0];
            this->ProjAtivo = (bool)ativo;
        }

        InimigoMedio::~InimigoMedio(){}

        void InimigoMedio::operator--(const int dano){
            num_vidas-=dano;
        }

        void InimigoMedio::movimentoAleatorio(){
            if(moveAleatorio == 0){
                forca.x = 300.0f;
            }else{
                forca.x = -300.0f;
            }
        }

        void InimigoMedio::atirarProjetil(sf::Vector2f pos, const bool direita){
            ProjAtivo = true;
            sf::Vector2f newPosition;
            if(direita){
                newPosition = sf::Vector2f(pos.x + 20.f, pos.y);
                pFase->newProjetil(newPosition, direita);
            }else{
                newPosition = sf::Vector2f(pos.x - 20.f, pos.y);
                pFase->newProjetil(newPosition, direita);
            }
        }

        void InimigoMedio::deletarProjetil(){
            ProjAtivo = false;
            pFase->deleteProjetil();
        }

        const bool InimigoMedio::getProjAtivo(){
            return this->ProjAtivo;
        }

        void InimigoMedio::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = getBody()->getPosition();
            bool direita;
            
            if((((fabs(posJogador.x - posInimigo.x) <= RANGE) && (fabs(posJogador.y - posInimigo.y <= RANGE))) && (!ProjAtivo))){
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
            Entidade::body->setPosition(pos);
            gColisao->Notify(static_cast<Entidades::Entidade*>(this));
        }

        void InimigoMedio::tratarColisao(Entidade *entidade){
  
        }

        void InimigoMedio::executar(){
            move();
        }

        void InimigoMedio::update(){
            executar();
        }
        void InimigoMedio::salvar(std::ostringstream* entrada){
            (*entrada) << "{ \"ID\": [" << 3 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "], \"Vida\": [" << this->getNum_vidas() << "], \"Ativo\": [" << this->getProjAtivo() << "] }" << std::endl;
        }
    }
}