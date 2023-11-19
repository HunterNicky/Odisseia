#include "..\..\include\Observadores\ControleMenu.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleMenu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleMenu::ControleMenu(Menu::Menu* pMenu):
    Observer(),
    pMenu(pMenu),
    cima("Up"), baixo("Down"), enter("Enter"), fechar("Escape"){
    }

    ControleMenu::~ControleMenu(){
    }

    void ControleMenu::setMenu(Menu::Menu* pMenu){
        this->pMenu = pMenu;
    }
    void ControleMenu::notifyPressed(const std::string key){
        if(pMaquinaDeEstado->getEstadoAtual() == static_cast<Estados::Estado*>(pMenu)){
            if(pMenu && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
                if(key == enter){
                    switch (pMaquinaDeEstado->getEstadoAtual()->getID()) {
                        case(0): //MenuPrincipal
                            pMenu->executar();
                        break;
                        case(1): //MenuPausa
                            std::cout << "estive aq" << std::endl;
                            pMenu->executar();
                        break;
                        default:
                        break;
                    }
                }else if(key == fechar){
                    pMaquinaDeEstado->popEstado();
                }else if(key == cima){
                    pMenu->select(true);
                }else if(key == baixo){
                    pMenu->select(false);
                }
            }
        }
    }

    void ControleMenu::notifyReleased(const std::string key){}
}
