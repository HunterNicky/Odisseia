#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Estados/Fases/json.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        void Jogador::inicializa(){
            vel = sf::Vector2f(0.0f, 0.0f);
            body->setFillColor(sf::Color::Blue);
            this->num_vidas = 1000;
        }

        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Personagem(pos, size, id)
        {
            inicializa();
        }

        Jogador::Jogador(nlohmann::json atributos, const int pos, const Entidades::ID id):
            Personagem(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_X_JOGADOR, TAM_Y_JOGADOR), id){
            
            this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
            body->setFillColor(sf::Color::Blue);
            this->num_vidas = 1000;
        }
        Jogador::~Jogador(){}   

        void Jogador::operator--(const int dano){
            std::cout << num_vidas << std::endl;
            this->num_vidas-=dano;
        }

        void Jogador::move(){
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Jogador::pular(){
            if (onFloor) {
                forca.y = -20000.f;
                onFloor = false;
            }else{
                forca.y = 0;
            }
        }

        void Jogador::neutralizarInimigo(Entidade* pInimigo){
            if(pInimigo){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(pInimigo);
                    pPers->operator--(2);
                    //deletar personagem
                }
            }
        }
        void Jogador::tratarColisao(Entidade* entidade){
            switch (entidade->getId())
            {
            case (ID::InimigoFacil):
                neutralizarInimigo(entidade);
                break;
            case (ID::Plataforma):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Caixa):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Gosma):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            case (ID::Lava):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                break;
            default:
                break;
            }
        }

        void Jogador::direcionar(bool side){
            if(side){
                forca.x = 3000.f; 
            }else{
                forca.x = -3000.f;
            }
            if(!(onFloor)) pular();
            else vel.y = 0;
        }

        void Jogador::parar(){
            forca.x = 0;
        }

        void Jogador::executar(){
            move();
        }

        void Jogador::update(){
            executar();
        }

        void Jogador::salvar(std::ostringstream* entrada){
            (*entrada) << "{ \"ID\": [" << 1 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "] }" << std::endl;
        }
    }
}