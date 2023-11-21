#include "..\..\include\Menu\MenuPrincipal.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "Menu/MenuPrincipal.hpp"
#include <fstream>
#include <string>

namespace Menu{
    Estados::MaquinaDeEstado* MenuPrincipal::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    MenuPrincipal::MenuPrincipal(Estados::Jogo* pJogo):
        Menu(0, 5, sf::Vector2f(POS_BOTAO_X, POS_BOTAO_Y), sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "MINION++", 180),
        pJogo(pJogo), pOpcao(nullptr){
        fase2 = nullptr;
        inicializaBotao();
        titulo.setColor(sf::Color::Green);
    }

    MenuPrincipal::~MenuPrincipal(){
        if(fase2 != nullptr){
            delete fase2;
        }/*
        if(pOpcao != nullptr){
            delete pOpcao;
        }*/
        pGrafico->close();
    }

    void MenuPrincipal::update(const double dt){
        Menu::update(dt);
        pControleMenu->setMenu(this);
    }

    void MenuPrincipal::carregarJogo(){
    }

    void MenuPrincipal::executar(){
        switch(numSelec){
            case 0:
                fase2 = new Fases::Fase2();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(fase2));
                break;
            case 1:
                pOpcao = new MenuOpcoes();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pOpcao));
                break;
            case 2: {
                nlohmann::json arquivoEntidades;
                std::ifstream arquivo("data/Save/arquivoEntidades.json");
                arquivo >> arquivoEntidades;

                if(!arquivo){
                    std::cout << "ERRO AO ABRIR ARQUIVO_ENTIDADES!"<< std::endl;
                }
                fase2 = new Fases::Fase2(arquivoEntidades);
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(fase2));}
                break;
            case 3:{
                MenuRanking* pRanking = new MenuRanking();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pRanking));}
                break;
            case 4:
                pGrafico->close();
                pMaquinaDeEstado->popEstado();
                break;
            default:
                break;
        }
    }

    void MenuPrincipal::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;
        
        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 -50), std::string(" Novo Jogo"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 50), std::string(" Opcoes"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 150), std::string(" Carregar"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 250), std::string(" Ranking"));
        Menu::lBotao.push_back(pBotao);

        pBotao = new Botoes::Botao(sf::Vector2f(0.f, 720.f / 5 + 350), std::string(" Sair"));
        Menu::lBotao.push_back(pBotao);
        numOpc = 3;
    }

    void MenuPrincipal::draw(){
        Menu::draw();
    }
}
