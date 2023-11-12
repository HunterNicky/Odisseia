#include "..\..\include\Menu\MenuPrincipal.hpp"
#include "Menu/Menu.hpp"
#include <string>

namespace Menu{
    Estados::MaquinaDeEstado* MenuPrincipal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    MenuPrincipal::MenuPrincipal(Estados::Jogo* pJogo):
    Menu(),
    pJogo(pJogo){
        Botoes::Botao* pBotao = NULL;
        fase1 = NULL;

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4), std::string("Jogar"));
        pBotao->selecionado(true);
        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 100), std::string("Opcoes"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 200), std::string("Carregar"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 4 + 300), std::string("Sair"));
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
