#include "..\..\include\Fases\Fase1.hpp"

namespace Fases{
    Fase1::Fase1():
        Fase()
    {}
    Fase1::~Fase1(){}

    void Fase1::loadMap(){
        std::ifstream file("C:\\Users\\gabri\\OneDrive\\Documentos\\MateriasFaculdade\\TecProg\\Gigantes-\\data\\mapa.txt");
        sf::Vector2f pos(0.f, 0.f);
        char numero;

        while(file.get(numero)){
            switch (numero)
            {
            case '0':
                pos.x += 50.f;
                break;
            case '1':
                pos.x += 20.f;
                newJogador(pos,sf::Vector2f(50.f, 50.f));
                break;
            case '2':
                pos.x += 20.f;
                newInimigo(pos, sf::Vector2f(40.f, 40.f));
                break;
            case '3':
                pos.x += 200.f;
                newPlataforma(pos, sf::Vector2f(200.f, 50.f));
                break;
            case 'c':
                pos.x += 40.0f;
                newObstaculo(pos, sf::Vector2f(40.0f, 50.0f));
                break;
            case 'g':
                pos.x += 40.0f;
                newGosma(pos, sf::Vector2f(40.0f, 10.0f));
                break;
            case 'l':
                pos.x += 40.0f;
                newLava(pos, sf::Vector2f(40.0f, 10.0f));
                break;
            default:
                pos.x = 0;
                pos.y += 80.f;
                break;
            }
        }
        file.close();
    }
}

