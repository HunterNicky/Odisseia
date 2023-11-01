#pragma once

namespace Lista {
    template <class TE>
    class Elemento {
    private:
        Elemento<TE>* pNext;
        TE* pData;
    public:
        Elemento(TE* data);
        ~Elemento();
        void setNext(Elemento<TE>* prox);
        TE* getData();
        Elemento<TE>* getNext();
    };

    template<class TE>
    Elemento<TE>::Elemento(TE* data):
        pNext(nullptr),
        pData(data) {}

    template<class TE>
    Elemento<TE>::~Elemento(){}

    template<class TE>
    void Elemento<TE>::setNext(Elemento<TE>* prox){pNext = prox;}

    template<class TE>
    TE* Elemento<TE>::getData(){return pData;}

    template<class TE>
    Elemento<TE>* Elemento<TE>::getNext(){return pNext;}
}
