#include "..\..\include\Observadores\ControleMenu.hpp"
#include "Estados/Estado.hpp"
#include "Menu/Menu.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleMenu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();
    Observadores::ControleMenu* Observadores::ControleMenu::instance = nullptr;

    ControleMenu::ControleMenu():
    Observer(),
    pMenu(nullptr),
    cima("Up"), baixo("Down"), enter("Enter"), fechar("Escape"){
    }

    ControleMenu* ControleMenu::getInstance(){
        if(instance == nullptr){
            instance = new ControleMenu();
        }
        return instance;
    }

    ControleMenu::~ControleMenu(){
    }

    void ControleMenu::setMenu(Menu::Menu* pMenu){
        this->pMenu = pMenu;
    }
    void ControleMenu::notifyPressed(const std::string key){
        if(dynamic_cast<Menu::Menu*>(pMaquinaDeEstado->getEstadoAtual())){
            if(pMenu && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
                if(key == enter){
                    pMenu->executar();
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
