#pragma once

namespace Lista{
    template <class TE>
    class Elemento{
        private:
            Elemento<TE>* pNext;
            TE* pData;
        public:
            Elemento();
            ~Elemento();
            void setNext(Elemento<TE>* prox);
            void setData(TE* elemento);
            Elemento<TE>* getNext();
            TE* getData();
    };
    
    template<class TE>
    Elemento<TE>::Elemento():
        pNext(nullptr),
        pData(nullptr){}

    template<class TE>
    Elemento<TE>::~Elemento(){}

    template<class TE>
    void Elemento<TE>::setNext(Elemento<TE>* pNext){this->pNext = pNext;}

    template<class TE>
    void Elemento<TE>::setData(TE* pData){this->pData = pData;}

    template<class TE>
    Elemento<TE>* Elemento<TE>::getNext(){return pNext;}

    template<class TE>
    TE* Elemento<TE>::getData(){return pData;}
}