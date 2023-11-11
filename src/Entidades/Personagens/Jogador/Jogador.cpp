    #include "..\..\..\..\include\Entidades\Personagens\Jogador\Jogador.hpp"
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
            void Personagens::Jogador::tratarColisao(){}
    }
}