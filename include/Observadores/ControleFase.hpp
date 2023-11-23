#pragma once

#include "Menu/MenuPausa.hpp"
#include "Observer.hpp"

namespace Fases {
    class Fase;
}
namespace Estados {
    class MaquinaDeEstado;
}

namespace Menu {
    class MenuPausa;
}

namespace Observadores {
    class ControleFase : public Observer {
    private:
    public:
        static Estados::MaquinaDeEstado* pMaquinaDeEstado;
        Fases::Fase* pFase;
        Menu::MenuPausa* pPausa;
        std::string cima, baixo, enter, fechar;
    public:
        ControleFase();
        ~ControleFase();
        void setFase(Menu::MenuPausa* pPausa);
        void jogadorMorreu();
        void notifyPressed(const sf::Keyboard::Key key);
        void notifyReleased(const sf::Keyboard::Key key);
    };
}
