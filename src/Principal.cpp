#include "..\include\Principal.hpp"
#include <iostream>

Gerenciadores::GerenciadorGrafico* Principal::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
Estados::MaquinaDeEstado* Principal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

Principal::Principal(){
    Estados::Fases::Fase1* fase1 = new Estados::Fases::Fase1();
    pMaquinaDeEstado->pushEstado(fase1);

    executar();
}

Principal::~Principal(){
}

void Principal::executar(){
    while (pGrafico->isWindowOpen()){
        pMaquinaDeEstado->atualizarEstadoAtual();
    }
}