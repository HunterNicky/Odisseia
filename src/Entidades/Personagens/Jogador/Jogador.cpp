#include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include "Animacao/AnimacaoParado.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>
namespace Entidades{
    namespace Personagens{
        void Jogador::inicializa(){
            vel = sf::Vector2f(0.0f, 0.0f);
            num_vidas = 1000;
            contextoAnimacao.setStrategy(static_cast<Animacao::AnimacaoStrategy*>(&parado), 0.1f);
            estamina = 1.f;
        }

        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Personagem(pos, size, id), 
            andar(static_cast<Entidades::Entidade*>(this) ,"data\\Sprites\\Jogador\\PlayerWalk.png",
            "data\\Sprites\\Jogador\\PlayerRun.png" , 8, 8), 
            parado(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Jogador\\PlayerIdle.png", 10),
            pulando(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Jogador\\PlayerJump.png", 
            "data\\Sprites\\Jogador\\PlayerSpin.png", 3, 6),
            contextoAnimacao()
        {
            inicializa();
        }

        Jogador::~Jogador(){}   

        void Jogador::operator--(const int dano){
            std::cout << num_vidas << std::endl;
            num_vidas-=dano;
        }

        void Jogador::move(){
            Entidade::body->setPosition(pos);
            if(onFloor){
                if(std::abs(vel.x) > 0.3f){
                    contextoAnimacao.setStrategy(&andar, 0.1f);
                }else{
                    contextoAnimacao.setStrategy(&parado, 0.5f);
                }
            }else if (vel.y < -0.5f){
                contextoAnimacao.setStrategy(&pulando, 0.1f);
            }
            contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
            gColisao->Notify(static_cast<Entidades::Entidade*>(this));
        }

        void Jogador::direcionar(bool side){
            if(side){
                forca.x = 5000.f; 
            }else{
                forca.x = -5000.f;
            }
            if(!onFloor)forca.y = 0;
        }

        void Jogador::correr(){
            if(estamina < 0.1f){
                estamina = 0.1f;
                if(forca.x > 0.f){
                    direcionar(true);
                }else{
                    direcionar(false);
                }
            }else{
                estamina -= gFisico->getDeltaTime();
                if(forca.x != 0.f){
                    if(estamina > 0.4f)forca.x *= 1.01f;
                    else forca.x /= 1.01f;
                }
            }
        }

        void Jogador::pular(){
            jumpTime += gFisico->getDeltaTime();
            if(onFloor && jumpTime < gFisico->getDeltaTime() * 3){
                forca.y = -80000.f;
            }else{
                forca.y = 0;
            }
            if(jumpTime > gFisico->getDeltaTime() * 6){
                jumpTime = gFisico->getDeltaTime() * 6;
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
            case (ID::Inimigo):
                neutralizarInimigo(entidade);
                break;
            case (ID::Plataforma):
                entidade->tratarColisao(static_cast<Entidades::Entidade*>(this));
                pos.x -= vel.x*0.01;
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

        const float Jogador::getEstamina() const{
            return estamina;
        }


        void Jogador::parar(){
            forca.x = 0;
        }

        void Jogador::executar(){
            move();
        }

        void Jogador::update(){
            if(estamina < 1.f)estamina += estamina*0.0001f + 0.001f;
            executar();
        }
    }
}