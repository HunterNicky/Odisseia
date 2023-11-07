#include "..\..\include\Estados\Estado.hpp"

namespace Estados{

    Estado::Estado(MaquinaDeEstado *pMaqEstado, unsigned int id):
    pMaqEstado(pMaqEstado), id(id){
    }

    Estado::~Estado(){
    }

    void Estado::setMaquinaDeEstado(MaquinaDeEstado *pMaqEstado){this->pMaqEstado = pMaqEstado;}

    unsigned int Estado::getID() const{return id;}
    
}

