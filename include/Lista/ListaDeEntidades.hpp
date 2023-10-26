#pragma once

#include "Lista.hpp"
#include "..\Entidades\Entidade.hpp"

namespace Lista{
    class ListaDeEntidades{
        private:
            Lista<Entidades::Entidade> LE;

        public:
            ListaDeEntidades();
            ~ListaDeEntidades();
            Entidades::Entidade* pop(Entidades::Entidade* pData);
            Entidades::Entidade* pop(unsigned int index);
            Entidades::Entidade* getFirst();
            Entidades::Entidade* getLast();
            Entidades::Entidade* operator[](unsigned int index);
            void push_back(Entidades::Entidade* pData);
            void remove(Entidades::Entidade* pData);
            void remove(unsigned int index);
            void drawAll();
            void updateAll();
            void clear();
            const bool getEmpty();
            unsigned int getSize();
    };
}