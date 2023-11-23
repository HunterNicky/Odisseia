#include "Gerenciadores/Mediator.hpp"
#include "Entidades/Entidade.hpp"
#include "Lista/ListaDeEntidades.hpp"


namespace Gerenciadores {
Mediator::Mediator() {}

Mediator::~Mediator() { LE->clear(); }
} // namespace Gerenciadores
