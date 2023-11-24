#pragma once

#include "..\Observadores\Observer.hpp"
#include "GerenciadorGrafico.hpp"
#include <list>


namespace Gerenciadores {
class GerenciadorDeEvento {
private:
  static GerenciadorGrafico *pGrafico;
  static GerenciadorDeEvento *pEvento;
  std::list<Observadores::Observer *> lObserver;
  bool removido;
  GerenciadorDeEvento();

public:
  ~GerenciadorDeEvento();
  static GerenciadorDeEvento *getInstance();
  void addObserver(Observadores::Observer *observer);
  void removeObserver(Observadores::Observer *observer);
  void stage();
};
} // namespace Gerenciadores