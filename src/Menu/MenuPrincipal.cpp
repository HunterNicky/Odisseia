#include "..\..\include\Menu\MenuPrincipal.hpp"

namespace Menu{
    Estados::MaquinaDeEstado* MenuPrincipal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    MenuPrincipal::MenuPrincipal(Estados::Jogo* pJogo):
    Menu(),
    pJogo(pJogo){
        Botoes::Botao* pBotao = NULL;
        fase1 = new Estados::Fases::Fase1();

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720 / 3), "Jogar");
        pBotao->selecionado(true);
        lBotao.push_back(pBotao);
        it = lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720 / 3 + 100), "Pontação");
        lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720 / 3 + 200), "Configuração");
        lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(1280 / 2.0f, 720 / 3 + 300), "Sair");
        lBotao.push_back(pBotao);
        numOpc = 3;
    }

    MenuPrincipal::~MenuPrincipal(){
    }

    void MenuPrincipal::update(double dt, double alpha){
        draw();
    }

    void MenuPrincipal::draw(){
        for (it = lBotao.begin(); it != lBotao.end(); ++it){
            (*it)->draw();  
            (*it)->update();
        }
    }

    void MenuPrincipal::executar(){
        switch(numSelec){
            case 0:
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(fase1));
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                pGrafico->close();
                break;
            default:
                break;
        }
    }
}
