#include "..\include\Principal.hpp"

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();

Principal :: Principal ()
{
    primeiraFase.loadMap();
    executar();
}

Principal :: ~Principal(){

}
void Principal::executar(){

    while(pGrafico->isWindowOpen()){
        primeiraFase.executar();
    }
}





