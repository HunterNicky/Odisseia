#include "..\..\include\Estados\Jogo.hpp"

namespace Estados{
    Gerenciadores::GerenciadorGrafico* Jogo::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
    Gerenciadores::GerenciadorDeEvento* Jogo::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
    Estados::MaquinaDeEstado* Jogo::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    Jogo::Jogo(){
        Menu::MenuPrincipal* pMenuP = new Menu::MenuPrincipal(this);
        pMaquinaDeEstado->pushEstado(static_cast<Estado*>(pMenuP));
        Observadores::ControleMenu* pControlMenu = new Observadores::ControleMenu(pMenuP);
        pEvento->addObserver(static_cast<Observadores::Observer*>(pControlMenu));
        t = 0.0;
        dt = 0.01;
        currentTime = clock.getElapsedTime().asSeconds();
        accumulator = 0.0;

        executar();
    }

    Jogo::~Jogo(){
    }

    void Jogo::atualizarJogo(){
        pEvento->stage();
        t += dt;
        pMaquinaDeEstado->atualizarEstadoAtual(dt, 1.f);
    }

    void Jogo::executar(){
        while (pGrafico->isWindowOpen()){
            pGrafico->clear();

            double newTime = clock.getElapsedTime().asSeconds();
            double frameTime = newTime - currentTime;
            if (frameTime > 0.16)
                frameTime = 0.16;
            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt){
                atualizarJogo();
                accumulator -= dt;
            }

            pMaquinaDeEstado->desenharEstadoAtual();
            pGrafico->display();
        }
    }
}