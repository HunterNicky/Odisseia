#pragma once
namespace Entidades{
    class Entidade;
}

namespace Lista{
    class ListaDeEntidades;
}

namespace Gerenciadores{
    class Mediator{
        protected:
            Lista::ListaDeEntidades* LE;
        public:
            Mediator();
            ~Mediator();
            virtual void setList(Lista::ListaDeEntidades* LE) = 0;
            virtual void Notify(Entidades::Entidade* entidade) = 0;
    };

}
