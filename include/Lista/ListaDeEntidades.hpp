#pragma once

#include "..\Entidades\Entidade.hpp"
#include "Lista.hpp"
#include "Lista/Lista.hpp"
#include "Lista/ListaDeEntidades.hpp"


namespace Entidades {
class Entidade;
}
namespace Lista {
class ListaDeEntidades {
private:
  Lista<Entidades::Entidade> LE;

public:
  ListaDeEntidades();
  ~ListaDeEntidades();
  Entidades::Entidade *pop(Entidades::Entidade *pData);
  Entidades::Entidade *pop(const unsigned int index);
  Entidades::Entidade *getFirst();
  Entidades::Entidade *getLast();
  Entidades::Entidade *operator[](const unsigned int index);
  void push_back(Entidades::Entidade *pData);
  void remove(Entidades::Entidade *pData);
  void remove(const unsigned int index);
  void drawAll();
  void updateAll();
  void clear();
  const bool getEmpty();
  unsigned int getSize();
  Lista<Entidades::Entidade>::Iterator getPrimeiro();
};
} // namespace Lista