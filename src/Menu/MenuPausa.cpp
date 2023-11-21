#include "Menu/MenuPausa.hpp"
#include "Observadores/ControleMenu.hpp"
#include "Fases/Fase.hpp"

namespace Menu {
    MenuPausa::MenuPausa(Fases::Fase* pFase):
        Menu(2, 3, sf::Vector2f(POS_TEXTO_PAUSE_X - TAM_TEXTO_PAUSE_X, POS_TEXTO_PAUSE_Y - TAM_TEXTO_PAUSE_X / 2), sf::Vector2f(TAM_TEXTO_PAUSE_X, TAM_TEXTO_PAUSE_Y), "PAUSE", 100),
        pFase(pFase)
    {
        inicializaBotao();
        titulo.setColor(sf::Color::Red);
    }
    MenuPausa::~MenuPausa(){
    }
    
    void MenuPausa::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f - 100), std::string(" Voltar "));
        pBotao->selecionado(true);
        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f ), std::string(" Salvar Jogo"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f + 100), std::string(" Sair "));
        Menu::lBotao.push_back(pBotao);
    }
    
    void MenuPausa::executar(){
        switch(numSelec){
            case 0:
                pMaquinaDeEstado->popEstado();
                break;
            case 1:
                 pMaquinaDeEstado->popEstado();
                 pMaquinaDeEstado->popEstado();
                break;
            case 2:
                pMaquinaDeEstado->popEstado();
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }

    }
    void MenuPausa::update(const double dt){
        Menu::update(dt);
    }

    void MenuPausa::draw(){
        pFase->draw();
        Menu::draw();
    }

}