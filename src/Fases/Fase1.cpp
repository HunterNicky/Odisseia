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
                pos.x += 20.f;
                break;
            case '1':
                pos.x += 20.f;
                newJogador(pos,sf::Vector2f(30.f, 50.f));
                break;
            case '2':
                pos.x += 20.f;
                newInimigo(pos, sf::Vector2f(20.f, 30.f));
                break;
            case '3':
                pos.x += 200.f;
                newObstaculo(pos, sf::Vector2f(200.f, 50.f));
                break;
            default:
                pos.x = 0;
                pos.y += 200.f;
                break;
            }
        }
        file.close();
    }
}

