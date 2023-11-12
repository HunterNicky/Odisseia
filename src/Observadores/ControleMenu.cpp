#include "..\..\include\Observadores\ControleMenu.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleMenu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleMenu::ControleMenu(Menu::Menu* pMenu):
    Observer(),
    pMenu(pMenu),
    cima("Up"), baixo("Down"), fechar("Escape"), enter("Enter"){
    }

    ControleMenu::~ControleMenu(){
    }

    void ControleMenu::setMenu(Menu::Menu* pMenu){
        this->pMenu = pMenu;
    }
    void ControleMenu::notifyPressed(std::string key){
        if(pMaquinaDeEstado->getEstadoAtual() == static_cast<Estados::Estado*>(pMenu)){
            if(pMenu && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
                if(key == cima){
                    pMenu->select(true);
                }else if(key == baixo){
                    pMenu->select(false);
                }
                if(key == enter){
                    pMenu->executar();
                }
                if(key == fechar){
                    pMaquinaDeEstado->popEstado();
                }
            }
        }
    }

    void ControleMenu::notifyReleased(std::string key){}
}
