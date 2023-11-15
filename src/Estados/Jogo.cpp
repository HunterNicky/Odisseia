#include "..\..\include\Estados\Jogo.hpp"

namespace Estados{
    Gerenciadores::GerenciadorGrafico* Jogo::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
    Gerenciadores::GerenciadorDeEvento* Jogo::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
    Estados::MaquinaDeEstado* Jogo::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();
    const sf::Time mTPF = sf::seconds(1.0f / 120.0f);

    Jogo::Jogo(){
        Menu::MenuPrincipal* pMenuP = new Menu::MenuPrincipal(this);
        pMaquinaDeEstado->pushEstado(static_cast<Estado*>(pMenuP));
        Observadores::ControleMenu* pControlMenu = new Observadores::ControleMenu(pMenuP);
        pEvento->addObserver(static_cast<Observadores::Observer*>(pControlMenu));

        executar();
    }

    Jogo::~Jogo(){
    }
    void Jogo::atualizarJogo(){
        pEvento->stage();
        pMaquinaDeEstado->atualizarEstadoAtual(mTPF.asSeconds());
    }

    void Jogo::executar(){
        tick = clock.restart();
        while (pGrafico->isWindowOpen()){
            pGrafico->clear();
            dt = clock.restart();
            tick += dt;
            while(tick > mTPF){
                atualizarJogo();
                tick -= mTPF;
            }
            pMaquinaDeEstado->desenharEstadoAtual();
            pGrafico->display();
        }
    }
}