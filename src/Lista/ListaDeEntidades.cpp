#include "..\..\include\Lista\ListaDeEntidades.hpp"
#include <iostream>

namespace Lista{
    ListaDeEntidades::ListaDeEntidades(){}

    ListaDeEntidades::~ListaDeEntidades(){clear();}

    Entidades::Entidade *ListaDeEntidades::pop(Entidades::Entidade *pData){return LE.pop(pData);}

    Entidades::Entidade *ListaDeEntidades::pop(unsigned int index){return LE.pop(index);}

    Entidades::Entidade *ListaDeEntidades::getFirst(){return LE.getFirst();}

    Entidades::Entidade *ListaDeEntidades::getLast(){return LE.getLast();}

    Entidades::Entidade *ListaDeEntidades::operator[](unsigned int index){return LE.operator[](index);}

    void ListaDeEntidades::push_back(Entidades::Entidade *pData){LE.push_back(pData);}

    void ListaDeEntidades::remove(Entidades::Entidade *pData){LE.remove(pData);}

    void ListaDeEntidades::remove(unsigned int index){LE.remove(index);}

    void ListaDeEntidades::drawAll(){
        if(LE[0] != nullptr){
            for(int i = 0; LE[i]==LE.getLast(); i++){
                LE[i]->draw();
                //cout << "|" << LE[i]->getPos().x << "|" << LE[i]->getPos().y << endl;
            }
        }
    }

    void ListaDeEntidades::updateAll(){
        if(LE[0] != nullptr){
            for(int i = 0; LE[i]==LE.getLast(); i++){
                LE[i]->update();
            }
        }
    }

    void ListaDeEntidades::clear(){LE.clear();}

    const bool ListaDeEntidades::getEmpty(){return LE.getEmpty();}

    unsigned int ListaDeEntidades::getSize(){return LE.getSize();}
}
