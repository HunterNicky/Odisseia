#pragma once

namespace Entidades {
class Entidade;
}

namespace Lista {
class ListaDeEntidades;
}

namespace Gerenciadores {
namespace Colisao {
class PadraoProjeto_Mediator {
protected:
  Lista::ListaDeEntidades *LE;

public:
  PadraoProjeto_Mediator();
  ~PadraoProjeto_Mediator();
  virtual void setList(Lista::ListaDeEntidades *LE) = 0;
  virtual void Notify(Entidades::Entidade *entidade) = 0;
};
} // namespace Colisao
} // namespace Gerenciadores
