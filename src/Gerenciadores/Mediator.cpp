#include "Gerenciadores/Mediator.hpp"
#include "Lista/ListaDeEntidades.hpp"
#include "Entidades/Entidade.hpp"

namespace Gerenciadores{
    Mediator::Mediator(){}

    Mediator::~Mediator(){
        LE->clear();
    }
}
