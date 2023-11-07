#pragma once

#include "Elemento.hpp"

namespace Lista{
    template <class TL>
    class Lista{
    private:
        Elemento<TL>* pFirst;
        Elemento<TL>* pLast;
        unsigned int size;
    
    //Nested
    public:
        class Iterator{
        private:
            Elemento<TL>* position;
        public:
            Iterator(Elemento<TL>* pos = nullptr);
            ~Iterator();
            TL operator*();
            void operator++();
            bool operator!= (const Iterator& it);
        };
    
    public:
        Lista();
        ~Lista();
        TL* pop(TL* pData);
        TL* pop(unsigned int index);
        TL* getFirst();
        TL* getLast();
        TL* operator[](unsigned int index);
        void push_back(TL* pData);
        void remove(TL* pData);
        void remove(unsigned int index);
        void clear();
        const bool getEmpty();
        unsigned int getSize();

    public:
        class Iterator{
            private:
                Elemento<TL>* position;
            public:
                Iterator(Elemento<TL>* position);
                ~Iterator();
                bool operator==(const Iterator& it);
                bool operator!=(const Iterator& it);
                Iterator operator++();
            
        };
    };
    
    template<class TL>
    Lista<TL>::Iterator::Iterator(Elemento<TL>* pos):
        position(pos)
    {}

    template<class TL>
    Lista<TL>::Iterator::~Iterator(){}

    template<class TL>
    TL Lista<TL>::Iterator::operator*(){
        return position->getData();
    }
    template<class TL>
    void Lista<TL>::Iterator::operator++(){
        position = position->getNext();
    }
    template<class TL>
    bool Lista<TL>::Iterator::operator!= (const Iterator& it){
        if(it.position->getData() != position->getData)
            return true;
        return false;
    }

    template<class TL>
    Lista<TL>::Lista():
        pFirst(nullptr),
        pLast(nullptr),
        size(0){}

    template<class TL>
    Lista<TL>::~Lista(){}

    template<class TL>
    TL* Lista<TL>::pop(TL* pData){
        Elemento<TL>* pAux = pFirst;
        Elemento<TL>* pPrev = nullptr;

        while (pAux != nullptr){
            if (pAux->getData() == pData){
                if (pAux == pFirst){
                    pFirst = pAux->getNext();
                }else{
                    if(pAux == pLast){
                        pLast = pPrev;
                    }
                    pPrev->setNext(pAux->getNext());
                }

                TL* poppedData = pAux->getData();
                delete pAux;
                size--;
                return poppedData;
            }

            pPrev = pAux;
            pAux = pAux->getNext();
        }
        return nullptr;
        
    }
    
    template <class TL>
    TL* Lista<TL>::pop(unsigned int index){
        if (index >= size || pFirst == nullptr){return nullptr;}

        Elemento<TL>* pAux = pFirst;
        Elemento<TL>* pPrev = nullptr;

        for (unsigned int i = 0; i < index; i++){
            pPrev = pAux;
            pAux = pAux->getNext();
        }

        if (pAux == pFirst){
            pFirst = pAux->getNext();
        }else{
            if (pAux == pLast){
                pLast = pPrev;
            }
            pPrev->setNext(pAux->getNext());
        }

        TL* poppedData = pAux->getData();
        delete pAux;
        size--;

        return poppedData;
    }
    template <class TL>
    TL* Lista<TL>::getFirst(){
        if (pFirst != nullptr){
            return pFirst->getData();
        }
        return nullptr;
    }

    template <class TL>
    TL* Lista<TL>::getLast(){
        if (pLast != nullptr){
            return pLast->getData();
        }
        return nullptr;
    }

    template <class TL>
    TL* Lista<TL>::operator[](unsigned int index) {
        if (index >= size || pFirst == nullptr){return nullptr;}

        Elemento<TL>* pAux = pFirst;
        for (unsigned int i = 0; i < index; i++){pAux = pAux->getNext();}

        return pAux->getData();
    }

    template <class TL>
    const bool Lista<TL>::getEmpty(){
        return size == 0;
    }

    template <class TL>
    unsigned int Lista<TL>::getSize(){
        return size;
    }

    template <class TL>
    void Lista<TL>::push_back(TL* pData){
        Elemento<TL>* pElement = new Elemento<TL>(pData);

        if (pFirst == nullptr){
            pFirst = pElement;
            pLast = pElement;
        } else {
            pLast->setNext(pElement);
            pLast = pElement;
        }
        size++;
    }


    template <class TL>
    void Lista<TL>::remove(TL* pData){
        Elemento<TL>* pAux = pFirst;
        Elemento<TL>* pPrev = nullptr;

        while(pAux != nullptr){
            if(pAux->getData() == pData){
                if(pAux == pFirst){
                    pFirst = pAux->getNext();
                }else{
                    if(pAux == pLast){
                        pLast = pPrev;
                    }
                    pPrev->setNext(pAux->getNext());
                }
                delete pAux;
                size--;
                return;
            }

            pPrev = pAux;
            pAux = pAux->getNext();
        }
    }

    template <class TL>
    void Lista<TL>::remove(unsigned int index){
        if(index >= size || pFirst == nullptr){return;}

        Elemento<TL>* pAux = pFirst;
        Elemento<TL>* pPrev = nullptr;

        for(unsigned int i = 0; i < index; i++){
            pPrev = pAux;
            pAux = pAux->getNext();
        }

        if(pAux == pFirst){
            pFirst = pAux->getNext();
        }else{
            if(pAux == pLast){
                pLast = pPrev;
            }
            pPrev->setNext(pAux->getNext());
        }
        delete pAux;
        size--;
    }

    template <class TL>
    void Lista<TL>::clear(){
        Elemento<TL>* pAux = pFirst;
        while(pAux != nullptr){
            Elemento<TL>* pTemp = pAux;
            pAux = pAux->getNext();
            delete pTemp;
        }

        pFirst = nullptr;
        pLast = nullptr;
        size = 0;
    }

    template <class TL>
    Lista<TL>::Iterator::Iterator(Elemento<TL> * position){
        this->position = position;
    }
    
    template <class TL>
    Lista<TL>::Iterator::~Iterator(){}

    template <class TL>
    bool Lista<TL>::Iterator::operator!=(const Iterator& it){
        return it.position != this->position;
    }

    template <class TL>
    bool Lista<TL>::Iterator::operator==(const Iterator& it){
        return it.position == this->position;
    }

    template <class TL>
    typename Lista<TL>::Iterator Lista<TL>::Iterator::operator++() {
        return this->position->getNext();
    }


}