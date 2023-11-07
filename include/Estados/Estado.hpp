#pragma once

namespace Estados{
    class MaquinaDeEstado;

    class Estado{

    protected:
        MaquinaDeEstado* pMaqEstado;
        unsigned int id;
    public:
        Estado(MaquinaDeEstado* pMaqEstado, unsigned int id);
        virtual ~Estado();
        void setMaquinaDeEstado(MaquinaDeEstado* pMaqEstado);
        unsigned int getID() const;
        virtual void update() = 0;
        //virtual void resetEstate() = 0;
    };

}