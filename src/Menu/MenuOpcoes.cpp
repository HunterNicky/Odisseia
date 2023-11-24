#include "Menu/MenuOpcoes.hpp"
#include "Fases/Fase.hpp"

namespace Menu {
    MenuOpcoes::MenuOpcoes(): 
        Menu(1, 2, sf::Vector2f(POS_TEXTO_OPTION_X - TAM_TEXTO_OPTION_X*1.5, POS_TEXTO_OPTION_Y -TAM_TEXTO_OPTION_Y/2), sf::Vector2f(TAM_TEXTO_OPTION_X, TAM_TEXTO_OPTION_Y), "OPCOES", 120),
        pBotao(nullptr){
        inicializaBotao();
        titulo.setColor(sf::Color::White);
    }

    MenuOpcoes::~MenuOpcoes(){/*
        if(pFase1 != nullptr){
            delete pFase1;
        }
        if(pFase2 != nullptr){
            delete pFase2;
        }*/
    }

    void MenuOpcoes::selecionaBotao(){
        if(pBotao!= nullptr){
            pBotao->selecionado(true);
            Menu::it = Menu::lBotao.begin();
        }
    }

    void MenuOpcoes::executar(){
        switch(numSelec){
            case 0: //Fase 1
                pFase1 = new Fases::Fase1();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pFase1));
                break;
            case 1: //Fase 2
                pFase2 = new Fases::Fase2();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pFase2));
                break;
            case 2:
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }
    void MenuOpcoes::inicializaBotao(){
         
        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f - 100), std::string(" Fase 1"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f), std::string(" Fase 2"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f + 100), std::string(" Voltar"));
        Menu::lBotao.push_back(pBotao);
        numOpc = 3;
    }

    void MenuOpcoes::update(const double dt){
        Menu::update(dt);
    }
    void MenuOpcoes::draw(){
        Menu::draw();
    }
}