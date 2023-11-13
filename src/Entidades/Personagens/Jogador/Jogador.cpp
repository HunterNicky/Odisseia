    #include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Personagem.hpp"
    #include "Gerenciadores/GerenciadorFisico.hpp"
    #include <iostream>
    namespace Entidades{
        namespace Personagens{
            void Jogador::inicializa(){
                vel = sf::Vector2f(0.0f, 0.0f);
                body->setFillColor(sf::Color::Blue);
            }

            Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size, const int id):
                Personagem(pos, size, id)
            {
                inicializa();
            }

            Jogador::~Jogador(){}   

            void Jogador::move(){   
                Entidade::gFisico->executarFisica(static_cast<Entidades::Entidade*>(this));
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

            void Jogador::direcionar(bool side){
                if(side){
                    forca.x = 3000.f; 
                }else{
                    forca.x = -3000.f;
                }
                if(!(onFloor)) pular();
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
            void Personagens::Jogador::tratarColisao(Entidade* entidade){
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