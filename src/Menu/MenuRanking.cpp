#include "Menu/MenuRanking.hpp"

namespace Menu {
    MenuRanking::MenuRanking():
        Menu(3, 1, sf::Vector2f(POS_TEXTO_RANKING_X - TAM_TEXTO_RANKING_X*1.5, POS_TEXTO_RANKING_Y - TAM_TEXTO_RANKING_Y /2), sf::Vector2f(TAM_TEXTO_RANKING_X, TAM_TEXTO_RANKING_Y), "RANKING", 100){
        inicializaBotao();
        titulo.setColor(sf::Color::Green);
    }
    MenuRanking::~MenuRanking(){}

    void MenuRanking::inicializaBotao(){ 
        Botoes::Botao* pBotao = NULL;
        
        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 720.f/4 * 3), std::string(" Voltar"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();
    }

    void MenuRanking::executar(){
        switch (numSelec) {
            case 0: //voltar
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }
    void MenuRanking::update(const double dt){
        Menu::update(dt);
    }
    void MenuRanking::draw(){
        Menu::draw();
    }
}