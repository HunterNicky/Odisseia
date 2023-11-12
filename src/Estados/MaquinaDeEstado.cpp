#include "..\..\include\Estados\MaquinaDeEstado.hpp"

namespace Estados{
    MaquinaDeEstado* MaquinaDeEstado::instance = nullptr;

    MaquinaDeEstado* MaquinaDeEstado::getInstance(){
        if(instance == nullptr){
            instance = new MaquinaDeEstado();
        }
        return instance;
    }

    MaquinaDeEstado::MaquinaDeEstado(){
        if (!estadoStack.empty()){
            delete estadoStack.top();
            estadoStack.pop();
        }
    }

    MaquinaDeEstado::~MaquinaDeEstado(){
    }

    void MaquinaDeEstado::pushEstado(Estado* estado){
        if(!estadoStack.empty())
                estadoStack.top()->setAtivo(false);
        estadoStack.push(estado);
    }

    void MaquinaDeEstado::popEstado(){
        if (!estadoStack.empty()){
            delete estadoStack.top();
            estadoStack.pop();
            if(!estadoStack.empty())
                estadoStack.top()->setAtivo(true);
        }
    }

    void MaquinaDeEstado::trocarEstado(Estado* estado){
        popEstado();
        pushEstado(estado);
    }

    void MaquinaDeEstado::atualizarEstadoAtual(double dt, double alpha){
        if(!estadoStack.empty()){
            estadoStack.top()->update(dt, alpha);
        }
    }

    void MaquinaDeEstado::desenharEstadoAtual(){
        if(!estadoStack.empty()){
            estadoStack.top()->draw();
        }
    }

    Estado* MaquinaDeEstado::getEstadoAtual()const{
        return !estadoStack.empty() ? estadoStack.top():nullptr;
    }
}
