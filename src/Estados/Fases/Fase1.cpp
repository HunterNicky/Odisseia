#include "..\..\..\include\Estados\Fases\Fase1.hpp"
#include "Estados/Fases/Fase1.hpp"

namespace Estados{
    namespace Fases{
        Fase1::Fase1(): 
            Fase(){
            loadMap();
        }
        Fase1::~Fase1(){
        }
        
        void Fase1::recuperarJogada(){

        }

        void Fase1::loadMap(){

            std::ifstream file("data\\mapa.txt");
            sf::Vector2f pos(0.f, 0.f);
            char numero;


            while(file.get(numero)){
                switch (numero)
                {
                case '0':
                    pos.x += 200.f;
                    break;
                case '1':
                    pos.x += 200.f;
                    newJogador(pos+sf::Vector2f(100.f, -200.f),sf::Vector2f(30.f, 50.f));
                    break;
                case '2':
                    pos.x += 200.f;
                    newInimigo(pos, sf::Vector2f(20.f, 30.f));
                case 'i':
                    pos.x += 20.f;
                    newInimigoMedio(pos, sf::Vector2f(20.f, 30.f));
                    break;
                case 'c':
                    pos.x += 20.0f;
                    newChefao(pos, sf::Vector2f(50.f, 50.f));
                    break;
                case '3':
                    pos.x += 200.f;
                    newObstaculo(pos, sf::Vector2f(200.f, 200.f));
                    break;
                default:
                    pos.x = 0;
                    pos.y += 50.f;
                    break;
                }
            }
            file.close();
        }
        void Fases::Fase1::draw(){
            Fase::draw();
        }

        void Estados::Fases::Fase1::update(){
        }

        void Estados::Fases::Fase1::executar(){
            Fase::executar();
        }
    }
}