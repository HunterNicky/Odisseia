#pragma once

#include "Observer.hpp"
#include "..\Menu\Menu.hpp"
#include "..\Estados\MaquinaDeEstado.hpp"

namespace Menu{
    class Menu;
}

namespace Observadores{
    class ControleMenu : public Observer{
        private:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            static ControleMenu* instance;
            Menu::Menu* pMenu;
            std::string cima, baixo, enter;
            std::string fechar;
            ControleMenu();
        public:
            ~ControleMenu();
            static ControleMenu* getInstance();
            void setMenu(Menu::Menu* pMenu);
            void notifyPressed(const std::string key);
            void notifyReleased(const std::string key);
    };
}