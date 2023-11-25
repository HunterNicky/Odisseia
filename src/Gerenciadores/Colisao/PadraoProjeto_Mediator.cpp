#include "Gerenciadores/Colisao/PadraoProjeto_Mediator.hpp"
#include "Entidades/Entidade.hpp"
#include "Lista/ListaDeEntidades.hpp"

namespace Gerenciadores {
namespace Colisao {
PadraoProjeto_Mediator::PadraoProjeto_Mediator() {}

PadraoProjeto_Mediator::~PadraoProjeto_Mediator() { LE->clear(); }
} // namespace Colisao
} // namespace Gerenciadores
