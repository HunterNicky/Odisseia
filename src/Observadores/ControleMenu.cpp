#include "..\..\include\Observadores\ControleMenu.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleMenu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleMenu::ControleMenu(Menu::Menu* pMenu):
    Observer(),
    pMenu(pMenu),
    cima("Up"), baixo("Down"), fechar("Escape"), enter("Enter"), ativo(true){
    }

    ControleMenu::~ControleMenu(){
    }

    void ControleMenu::setMenu(Menu::Menu* pMenu){
        this->pMenu = pMenu;
    }
    void ControleMenu::notifyPressed(std::string key){
        if(pMaquinaDeEstado->getEstadoAtual() == static_cast<Estados::Estado*>(pMenu)){
            if(pMenu){
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
    void ControleMenu::setAtivo(const bool ativo)
    {
        this->ativo = ativo;
    }

}
