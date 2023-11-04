#include "..\..\include\Fases\Fase1.hpp"

namespace Fases{
    Fase1::Fase1():
        Fase()
    {}
    Fase1::~Fase1(){}

    void Fase1::loadMap(){
        std::ifstream file("C:\\Users\\gabri\\OneDrive\\Documentos\\MateriasFaculdade\\TecProg\\Gigantes-\\data\\mapa.txt");
        std::string line;

        int j = 0;
        while(std::getline(file, line)){
            for(int i = 0; i < (int)line.size(); i++){
                if(line[i] != ' '){
                    newEntidade(line[i], sf::Vector2i(i, j));
                }
            }
            j++;
        }
        file.close();
    }
}

