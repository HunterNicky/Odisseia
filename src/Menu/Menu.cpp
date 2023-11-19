#include "../../include/Menu/Menu.hpp"
namespace Menu{
    Estados::MaquinaDeEstado* Menu::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    Menu::Menu(const int id):
    Estado(static_cast<Estados::MaquinaDeEstado*>(pMaquinaDeEstado), id),
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

    void Menu::update(const double dt){
        std::list<Botoes::Botao*>::iterator it2;
        it2 = lBotao.begin();
        pGrafico->setViewCenter(sf::Vector2f(1280.f/2, 720.f/2));
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
            it++;
            numSelec++;
            if (it == lBotao.end()) {
                it = lBotao.begin();
                numSelec = 0;
            }
        }
        (*it)->selecionado(true);
    }
}