#include "Menu/MenuPausa.hpp"
#include "Observadores/ControleMenu.hpp"

namespace Menu {
    MenuPausa::MenuPausa():
        Menu(1)
    {
        inicializaBotao();
        pControlePausa = new Observadores::ControleMenu(this);
    }
    MenuPausa::~MenuPausa(){
        if(pControlePausa){
            delete pControlePausa;
        }
    }
    void MenuPausa::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;

        pBotao = new Botoes::Botao(sf::Vector2f(1280.f / 2 - 200, 720.f / 2 - 100), std::string(" Salvar Jogo"));
        Menu::lBotao.push_back(pBotao);
        pBotao = new Botoes::Botao(sf::Vector2f(1280.f / 2 - 200, 720.f / 2 + 100), std::string(" Sair "));
        Menu::lBotao.push_back(pBotao);
    }
    
    void MenuPausa::executar(){
        if(numSelec == 0){
            pGrafico->close();
            pMaquinaDeEstado->popEstado();
        }
        std::cout << "menuPausa" << std::endl;

    }
    void MenuPausa::update(const double dt){
        Menu::draw();
        Menu::update(dt);
    }

}