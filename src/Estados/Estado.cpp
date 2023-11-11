#include "..\..\include\Estados\Estado.hpp"

namespace Estados{

    Estado::Estado(MaquinaDeEstado *pMaquinaDeEstado, unsigned int id):
    Ente(sf::Vector2f(0,0),sf::Vector2f(0,0)), pMaquinaDeEstado(pMaquinaDeEstado), id(id){
    }

    Estado::~Estado(){
    }

    void Estado::setMaquinaDeEstado(MaquinaDeEstado *pMaquinaDeEstado){this->pMaquinaDeEstado = pMaquinaDeEstado;}

    unsigned int Estado::getID() const{return id;}
    
}

