#include "..\..\include\Menu\MenuPrincipal.hpp"
#include "Menu/Menu.hpp"

namespace Menu{
    Estados::MaquinaDeEstado* MenuPrincipal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    MenuPrincipal::MenuPrincipal(Estados::Jogo* pJogo):
    Menu(),
    pJogo(pJogo){
        Botoes::Botao* pBotao = NULL;
        fase1 = NULL;

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720.f / 3), "Jogar");
        pBotao->selecionado(true);
        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720.f / 3 + 100), "Pontação");
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720.f / 3 + 200), "Configuração");
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720.f / 3 + 300), "Sair");
        Menu::lBotao.push_back(pBotao);
        numOpc = 3;
    }

    MenuPrincipal::~MenuPrincipal(){
    }

    void MenuPrincipal::update(double dt, double alpha){
        Menu::update();
    }

    void MenuPrincipal::draw(){
        Menu::draw();
    }

    void MenuPrincipal::executar(){
        switch(numSelec){
            case 0:
                fase1 = new Estados::Fases::Fase1();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(fase1));
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                pMaquinaDeEstado->popEstado();
                pGrafico->close();
                break;
            default:
                break;
        }
    }
}
