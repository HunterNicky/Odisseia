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
        currentTime = 0.0;
        accumulator = 0.0;
        executar();
    }

    Jogo::~Jogo() {
    }

    void Jogo::executar() {
        while (pGrafico->isWindowOpen()) {

            double newTime = clock.getElapsedTime().asSeconds();
            double frameTime = newTime - currentTime;
            if (frameTime > 0.25)
                frameTime = 0.25;
            currentTime = newTime;
            accumulator += frameTime;
            while (accumulator >= dt){
                t += dt;
                accumulator -= dt;
            }
            const double alpha = accumulator / dt;

            std::cout << alpha << std::endl;

            pGrafico->clear();

            pEvento->stage();

            pMaquinaDeEstado->atualizarEstadoAtual(dt, alpha);

            pGrafico->display();
        }
    }
}