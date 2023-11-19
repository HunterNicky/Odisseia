#include "..\..\..\..\include\Entidades\Personagens\Inimigo\InimigoFacil.hpp"
#include "Entidades/Personagens/Inimigo/Inimigo.hpp"
#include "Entidades/Personagens/Inimigo/InimigoFacil.hpp"
#include <sstream>
#include <stdlib.h>

namespace Entidades{
    namespace Personagens{
        void InimigoFacil::inicializa(){
            vel = sf::Vector2f(0.1f, 0.1f);
            body->setFillColor(sf::Color::Red);
            raio = RAIO;
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
        InimigoFacil::InimigoFacil(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_INIMIGO_FACIL_X, TAM_INIMIGO_FACIL_Y), id, pJog)
        {
            this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
            body->setFillColor(sf::Color::Red);
            this->num_vidas = 10;
            raio = RAIO;
            srand(time(NULL));
            this->raivosidade = rand()%10;
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
            moveAleatorio = rand()%4;
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

            if((fabs(posJogador.x - posInimigo.x) <= raio) && (fabs(posJogador.y - posInimigo.y) <= raio))
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
                pPers->operator--(dano);
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
        void InimigoFacil::salvar(std::ostringstream* entrada){
            (*entrada) << "{ \"ID\": [" << 2 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "] }" << std::endl;
        }
    }
}