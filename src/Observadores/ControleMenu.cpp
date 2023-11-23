#include "..\..\include\Observadores\ControleMenu.hpp"
#include "Estados/Estado.hpp"
#include "Menu/Menu.hpp"
#include "Menu/MenuGameOver.hpp"

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
    void ControleMenu::notifyPressed(const sf::Keyboard::Key key){
        if(dynamic_cast<Menu::Menu*>(pMaquinaDeEstado->getEstadoAtual())){
            if(pMenu && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
                if(keyboard[key] == enter){
                    pMenu->executar();
                }else if(keyboard[key] == fechar){
                    pMaquinaDeEstado->popEstado();
                }else if(keyboard[key] == cima){
                    pMenu->select(true);
                }else if(keyboard[key] == baixo){
                    pMenu->select(false);
                }
            }
        }
    }

    void ControleMenu::notifyReleased(const sf::Keyboard::Key key){
        if(pMaquinaDeEstado->getEstadoAtual()->getID() == 3){//menu Game Over
            if(keyboard[key] == "BackSpace"){
                pMenu->removerCaracter();
            }
            for(int i = 97; i < 123; i++){
                if(caracteres[key] == i){
                    pMenu->addCaracter(i);
                }
            }
            for(int i = 48; i < 58; i++){
                if(caracteres[key] == i){
                    pMenu->addCaracter(i);
                }
            }
        }
    }
}
