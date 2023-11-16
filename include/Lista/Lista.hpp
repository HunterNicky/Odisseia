#pragma once

namespace Lista{
    template <class TL>
    class Lista{
    public:
        //class Aninhada
        template <class TE>
        class Elemento {
        private:
            Elemento<TE>* pNext;
            TE* pData;

        public:
            Elemento(TE* data):
            pNext(nullptr),
            pData(data) {}

            ~Elemento(){}

            void setNext(Elemento<TE>* prox){pNext = prox;}

            TE* getData(){return pData;}

            Elemento<TE>* getNext(){return pNext;}
        };

    private:
        Elemento<TL>* pFirst;
        Elemento<TL>* pLast;
        unsigned int size;

    public:
        Lista();
        ~Lista();
        TL* pop(TL* pData);
        TL* pop(const unsigned int index);
        TL* getFirst();
        TL* getLast();
        TL* operator[](const unsigned int index);
        void push_back(TL* pData);
        void remove(TL* pData);
        void remove(const unsigned int index);
        void clear();
        const bool getEmpty();
        unsigned int getSize();

    public:
        //classe Aninhada 
        //Iterator - Padrão de Projeto
        class Iterator{
            private:
                Elemento<TL>* atual;
            public:
                Iterator(Elemento<TL>* elem = nullptr);
                ~Iterator();
                void operator=(Elemento<TL>* outro);
                bool operator==(const Iterator& it);
                bool operator!=(const Iterator& it);
                const Elemento<class TE>operator*();
                Iterator& operator++();
        };

         Lista<TL>::Iterator getPrimeiro();
    };

    template<class TL>
    Lista<TL>::Lista():
        pFirst(nullptr),
        pLast(nullptr),
        size(0){}

    template<class TL>
    Lista<TL>::~Lista(){clear();}

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
    TL* Lista<TL>::pop(const unsigned int index){
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
    TL* Lista<TL>::operator[](const unsigned int index) {
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
    void Lista<TL>::remove(const unsigned int index){
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
    Lista<TL>::Iterator::Iterator(Elemento<TL> * elem){
        this->atual = elem;
    }
    
    template <class TL>
    Lista<TL>::Iterator::~Iterator(){atual = nullptr;}

    template <class TL>
    void Lista<TL>::Iterator::operator=(Elemento<TL>* outro){
        this->atual = outro;
    }

    template <class TL>
    bool Lista<TL>::Iterator::operator!=(const Iterator& it){
        return it.atual != this->atual;
    }

    template <class TL>
    bool Lista<TL>::Iterator::operator==(const Iterator& it){
        return it.atual == this->atual;
    }

    template <class TL>
    typename Lista<TL>::Iterator& Lista<TL>::Iterator::operator++() {
        atual = atual->getNext();
        return (*this);
    }

    template <class TL>
    typename Lista<TL>::Iterator Lista<TL>::getPrimeiro(){
        return Iterator(pFirst);
    }
}