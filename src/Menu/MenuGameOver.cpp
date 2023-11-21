#include "Menu/MenuGameOver.hpp"
#include "Estados/Estado.hpp"
#include "Fases/Fase1.hpp"

namespace Menu {
    MenuGameOver::MenuGameOver(): Menu(3, 2, sf::Vector2f(POS_TEXTO_GO_X - TAMANHO_TEXTO_GO_X*2, POS_TEXTO_GO_Y - TAMANHO_TEXTO_GO_Y /2), sf::Vector2f(TAMANHO_TEXTO_GO_X, TAMANHO_TEXTO_GO_Y), "GAME OVER", 100){
        inicializaBotao();
        titulo.setColor(sf::Color::Red);
    }

    MenuGameOver::~MenuGameOver(){

    }
    void MenuGameOver::reiniciarFase(){
        while(pMaquinaDeEstado->getEstadoAtual()->getID() != 0){
            pMaquinaDeEstado->popEstado();
        }
    }
    void MenuGameOver::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;
         
        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f ), std::string(" Reiniciar"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f + 100), std::string(" Menu"));
        Menu::lBotao.push_back(pBotao);
        numOpc = 2;
    }
    void MenuGameOver::executar(){
        switch (numSelec) {
            case 0: // Reiniciar
                reiniciarFase();
                if(pMaquinaDeEstado->getEstadoAtual() != nullptr) { 
                    Fases::Fase1* pFase1 = new Fases::Fase1();
                    pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pFase1));
                }
                break;
            case 1:
                pMaquinaDeEstado->popEstado();
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }

    void MenuGameOver::update(const double dt){
        Menu::update(dt);
    }
    void MenuGameOver::draw(){
        Menu::draw();
    }
}