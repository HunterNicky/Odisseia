#pragma once

#include "GerenciadorGrafico.hpp"
#include "Observadores/Subject.hpp"

namespace Gerenciadores {
class GerenciadorDeEvento : public Observadores::Subject {
private:
  static GerenciadorGrafico *pGrafico;
  static GerenciadorDeEvento *pEvento;
  bool removido;
  GerenciadorDeEvento();

public:
  virtual ~GerenciadorDeEvento();
  static GerenciadorDeEvento *getInstance();
  void addObserver(Observadores::Observer *observer);
  void removeObserver(Observadores::Observer *observer);
  void notify();
};
} // namespace Gerenciadores