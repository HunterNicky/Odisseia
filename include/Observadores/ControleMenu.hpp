#pragma once

#include "..\Estados\MaquinaDeEstado.hpp"
#include "..\Menu\Menu.hpp"
#include "Observer.hpp"


namespace Menu {
class Menu;
}

namespace Observadores {
class ControleMenu : public Observer {
private:
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  static ControleMenu *instance;
  Menu::Menu *pMenu;
  std::string cima, baixo, enter;
  std::string fechar;
  ControleMenu();

public:
  ~ControleMenu();
  static ControleMenu *getInstance();
  void setMenu(Menu::Menu *pMenu);
  void notifyPressed(const sf::Keyboard::Key key);
  void notifyReleased(const sf::Keyboard::Key key);
};
} // namespace Observadores