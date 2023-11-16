#include "..\..\..\include\Estados\Fases\Fase2.hpp"
#include "Estados/Fases/Fase2.hpp"

namespace Estados{
    namespace Fases{
        Fase2::Fase2(): 
            Fase(){
            loadMap();
        }

        Fase2::~Fase2(){

        }

        void Fase2::newLava(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::Lava* pLava = new Entidades::Obstaculos::Lava(pos, size, Entidades::ID::Lava);
            pLava->setGerenciadorDeColisao(pColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pLava));
        }

        void Fase2::loadMap(){
            
            std::ifstream file("data//mapa.txt");
            sf::Vector2f pos(0.f, 0.f);
            char numero;

            while(file.get(numero)){
                switch (numero)
                {
                case '0':
                    pos.x += 20.f;
                    break;
                case '1':
                    pos.x += 20.f;
                    newJogador(pos,sf::Vector2f(30.f, 50.f));
                    break;
                case '2':
                    pos.x += 20.f;
                    newInimigo(pos, sf::Vector2f(20.f, 30.f));
                case 'i':
                    pos.x += 20.f;
                    newInimigoMedio(pos, sf::Vector2f(20.f, 30.f));
                    break;
                case '3':
                    pos.x += 200.f;
                    newObstaculo(pos, sf::Vector2f(200.f, 50.f));
                    break;
                case 'l':
                    pos.x += 40.f;
                    newLava(pos, sf::Vector2f(50.f, 10.f));
                    break;
                default:
                    pos.x = 0;
                    pos.y += 50.f;
                    break;
                }
            }
            file.close();
        }
        void Fase2::draw(){
            Fase::draw();
        }

        void Fase2::update(){
        }

        void Fase2::executar(){
            Fase::executar();
        }
    }
}