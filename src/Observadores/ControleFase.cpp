#include "Observadores/ControleFase.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Menu/MenuPausa.hpp"
#include <ostream>


namespace Observadores {
    Estados::MaquinaDeEstado* ControleFase::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleFase::ControleFase(): 
        Observer(), pFase(nullptr), pPausa(nullptr), cima("Up"), baixo("Down"), enter("Enter"), fechar("Escape"){}

    ControleFase::~ControleFase(){}

    void ControleFase::setFase(Menu::MenuPausa* pPausa){ this->pPausa = pPausa; }

    void ControleFase::jogadorMorreu(){}

    void ControleFase::notifyPressed(const std::string key){
        if(pPausa && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
            if(key == fechar){
                pMaquinaDeEstado->popEstado();
            }else if(key == cima){
                pPausa->select(true);
            }else if(key == baixo){
                pPausa->select(false);
            }
        }
    }

    void ControleFase::notifyReleased(const std::string key){}
}