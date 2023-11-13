#pragma once

#include "..\Ente.hpp"
namespace Estados{
    class MaquinaDeEstado;

    class Estado : public Ente{

    protected:
        MaquinaDeEstado* pMaquinaDeEstado;
        unsigned int id;
        bool ativo;
    public:
        Estado(MaquinaDeEstado* pMaquinaDeEstado, const unsigned int id);
        virtual ~Estado();
        void setMaquinaDeEstado(MaquinaDeEstado* pMaquinaDeEstado);
        const bool getAtivo() const;
        void setAtivo(const bool ativo);
        unsigned int getID() const;
        virtual void update(const double dt, const double alpha) = 0;
        virtual void executar() = 0;
        virtual void draw() = 0;
    };

}