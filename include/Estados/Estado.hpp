#pragma once

#include "..\Ente.hpp"
namespace Estados{
    class MaquinaDeEstado;

    class Estado : public Ente{

    protected:
        MaquinaDeEstado* pMaquinaDeEstado;
        unsigned int id;
    public:
        Estado(MaquinaDeEstado* pMaquinaDeEstado, unsigned int id);
        virtual ~Estado();
        void setMaquinaDeEstado(MaquinaDeEstado* pMaquinaDeEstado);
        unsigned int getID() const;
        virtual void update(double dt, double alpha);
        virtual void executar() = 0;
        virtual void draw() = 0;
        //virtual void resetEstate() = 0;
    };

}