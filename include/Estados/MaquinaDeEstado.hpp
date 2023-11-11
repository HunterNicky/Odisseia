#pragma once

#include "Estado.hpp"
#include <stack>

namespace Estados {

    class MaquinaDeEstado {
    private:
        std::stack<Estado*> estadoStack;
        static MaquinaDeEstado* instance;
        MaquinaDeEstado();
        
    public:
        static MaquinaDeEstado* getInstance();
        virtual ~MaquinaDeEstado();
        void pushEstado(Estado* estado);
        void popEstado();
        void trocarEstado(Estado* estado);
        void atualizarEstadoAtual(double dt, double alpha);
        Estado* getEstadoAtual() const;
    };
}
