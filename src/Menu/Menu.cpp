#include "../../include/Menu/Menu.hpp"
namespace Menu{
    Menu::Menu():
    Ente(sf::Vector2f(0,0), sf::Vector2f(1280, 720)), controleMenu(new Observadores::ControleMenu(this)), numSelec(0), numOpc(3){
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
        pGrafico->setViewCenter(sf::Vector2f(0, 0));
        draw();
    }

    void Menu::draw() {
        std::list<Botoes::Botao*>::iterator it2;
        for (it2 = lBotao.begin(); it2 != lBotao.end(); it2++) {
            Botoes::Botao* botao = *it2;
            botao->draw();
        }
    }
    
    void Menu::select(const bool direcao){
        it = lBotao.end();
        (*it)->selecionado(false);
        if (direcao){
            if (it == lBotao.begin()){
                it = lBotao.end();
                numSelec = (numOpc - 1);
            }else{
                numSelec--;
                it--;
            }
        }else{
            if (it == lBotao.end()){
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