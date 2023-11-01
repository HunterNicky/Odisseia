#include "..\..\..\include\Fase\Fase1\Fase1.hpp"


namespace Fase
{
    Fase1::Fase1(){

    }
    Fase1::~Fase1(){

    }
    void Fase1::Fase1::createMap(){
        std::ifstream file;
        std::string line;
        file.open();

        if(!file.is_open)
        {

        }
        int j = 0;

        while(std::getline(file, line)){
            for(int i = 0; i < line.size(); i++)
            {
                if(line[i] != ' ')
                {

                }
            }
            j++;
        }
        file.closed;
    }

}

