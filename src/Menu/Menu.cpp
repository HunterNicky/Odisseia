#include "../../include/Menu/Menu.hpp"
namespace Menu{
    Estados::MaquinaDeEstado* Menu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    Menu::Menu():
    Estado(static_cast<Estados::MaquinaDeEstado*>(pMaquinaDeEstado), 0),
    controleMenu(new Observadores::ControleMenu(this)), numOpc(3), numSelec(0)
    {
        controleMenu->setMenu(this);
    }

    Menu::~Menu(){
        Botoes::Botao* botao = NULL;
        while (lBotao.size() != 0){
            botao = lBotao.back();
            delete(botao);
            lBotao.pop_back();
        }
        lBotao.clear();
        delete controleMenu;
    }

    void Menu::update(){
        std::list<Botoes::Botao*>::iterator it2;
        it2 = lBotao.begin();
        pGrafico->setViewCenter((*it2)->getPos());
    }

    void Menu::draw() {
        std::list<Botoes::Botao*>::iterator it2;
        for (it2 = lBotao.begin(); it2 != lBotao.end(); it2++) {
            Botoes::Botao* botao = *it2;
            botao->draw();
        }
    }
    
    void Menu::select(const bool direcao){
        (*it)->selecionado(false);
        if (direcao){
            if (it == lBotao.begin()){
                it = --lBotao.end();
                numSelec = numOpc - 1;
            }else{
                numSelec--;
                it--;
            }
        }else{
            if (it == --lBotao.end()){
                it = lBotao.begin();
                numSelec = 0;
            }else{
                it++;
                numSelec++;
            }
        }
        (*it)->selecionado(true);
    }
}