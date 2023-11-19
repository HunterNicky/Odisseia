#include "Menu/MenuPausa.hpp"
#include "Observadores/ControleMenu.hpp"

namespace Menu {
    MenuPausa::MenuPausa():
        Menu(1,2)
    {
        inicializaBotao();
    }
    MenuPausa::~MenuPausa(){
    }
    
    void MenuPausa::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;

        pBotao = new Botoes::Botao(sf::Vector2f(1280.f / 2 - 200, 720.f / 2 - 100), std::string(" Salvar Jogo"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(1280.f / 2 - 200, 720.f / 2 + 100), std::string(" Sair "));
        Menu::lBotao.push_back(pBotao);
    }
    
    void MenuPausa::executar(){
        std::cout << "menuPausa" << std::endl;
        switch(numSelec){
            case 0:
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }
    void MenuPausa::update(const double dt){
        Menu::draw();
        Menu::update(dt);
    }

}