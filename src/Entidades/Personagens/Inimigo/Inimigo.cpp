#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"

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
                forca.x = 2500.f;
            }else{
                forca.x = -2500.f;
            }

            if(posJogador.y - posInimigo.y > 0.0f){
                forca.y = 20000.f;
            }else{
                forca.y = -20000.f;
            }
        }

        void Inimigo::move(){
            sf::Vector2f posJogador = pJogador->getBody()->getPosition();
            sf::Vector2f posInimigo = body->getPosition();

            persegueJogador(posJogador, posInimigo);

            
            Entidade::gFisico->executarFisica(static_cast<Entidades::Entidade*>(this));
            Entidade::body->setPosition(pos);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

        void Inimigo::executar(){
            move();
        }

        void Inimigo::update(){
            executar();
        }

        void Inimigo::tratarColisao(Entidade* entidade){
            gFisico->calColision(static_cast<Personagem*>(this), static_cast<Personagem*>(entidade));
            sf::Vector2f aux;
            aux.x = -vel.x;
            aux.y = -vel.y;
            aux.x *= 0.01f;
            aux.y *= 0.01f;
            pos += aux;
        }
    }

}
