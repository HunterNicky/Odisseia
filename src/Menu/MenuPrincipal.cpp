#include "..\..\include\Menu\MenuPrincipal.hpp"
#include "Estados/Fases/Fase2.hpp"
#include "Menu/Menu.hpp"
#include <string>

namespace Menu{
    Estados::MaquinaDeEstado* MenuPrincipal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    MenuPrincipal::MenuPrincipal(Estados::Jogo* pJogo):
        Menu(),
        pJogo(pJogo){
        fase2 = NULL;
        inicializaBotao();
    }

    MenuPrincipal::~MenuPrincipal(){
        pGrafico->close();
    }

    void MenuPrincipal::update(const double dt){
        Menu::update();
    }

    void MenuPrincipal::draw(){
        Menu::draw();
    }

    void MenuPrincipal::executar(){
        switch(numSelec){
            case 0:
                fase2 = new Estados::Fases::Fase2();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(fase2));
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                pGrafico->close();
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }

    void MenuPrincipal::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;
        
        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4), std::string(" Jogar"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 100), std::string(" Opcoes"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 200), std::string(" Carregar"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 300), std::string(" Sair"));
        Menu::lBotao.push_back(pBotao);
        numOpc = 3;
    }

}
