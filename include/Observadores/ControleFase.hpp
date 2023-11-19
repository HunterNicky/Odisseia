#include "Menu/MenuPausa.hpp"
#include "Observer.hpp"

namespace Estados {
    namespace Fases {
        class Fase;
    }
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
        Estados::Fases::Fase* pFase;
        Menu::MenuPausa* pPausa;
        std::string cima, baixo, enter, fechar;
    public:
        ControleFase();
        ~ControleFase();
        void setFase(Menu::MenuPausa* pPausa);
        void jogadorMorreu();
        void notifyPressed(const std::string key);
        void notifyReleased(const std::string key);
    };
}
