#ifndef LISTA_HPP
#define LISTA_HPP

#include "stdafx.hpp"
template <typename TL>
class Lista
{
    public:
    class Elemento
    {
        private:

            TL *pInfo;
            Elemento *pProx;

        public:

            Elemento(TL *pInfo);
            ~Elemento();

            TL* getInfo();
            void setProx(Elemento *pProx);
            //void incluir (TL *pInfo);
            Elemento* getProx();

    };

    private:

        Elemento *pPrimeiro;
        Elemento *pUltimo;
        int tamanho;

    public:

        Lista();
        ~Lista();

        void incluir (TL *pInfo);
        void limpar();

        Elemento* getPrimeiro();
        int getTamanho();

        //void imprimir();
        //void percorrer();
};

//Implamentação de template é no .hpp
// Elemento
template <typename TL>
Lista<TL>::Elemento::Elemento(TL* pInfo) : pInfo(pInfo), pProx(nullptr)
{

}

template <typename TL>
Lista<TL>::Elemento::~Elemento()
{
    pInfo = nullptr;    
    pProx = nullptr;
}

template <typename TL>
TL* Lista<TL>::Elemento::getInfo()
{
    return pInfo;
}

template <typename TL>
typename Lista<TL>::Elemento* Lista<TL>::Elemento::getProx()
{
    return pProx;
}

template <typename TL>
void Lista<TL>::Elemento::setProx(Elemento* pProx)
{
    this->pProx = pProx;
}

//Lista 
template <typename TL>
Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr), tamanho(0)
{

}

template <typename TL>
Lista<TL>::~Lista()
{
    limpar();
}

template <typename TL>
void Lista<TL>::incluir(TL* pInfo)
{
    if (pInfo == nullptr)
        return;

    Elemento* pNovo = new Elemento(pInfo);

    if (pPrimeiro == nullptr)
    {
        pPrimeiro = pNovo;
        pUltimo = pNovo;
    }

    else
    {
        pUltimo->setProx(pNovo);
        pUltimo = pNovo;
    }
    tamanho++;
}

template <typename TL>
void Lista<TL>::limpar()
{
    Elemento* pAux = pPrimeiro;

    while (pAux != nullptr)
    {
        Elemento* pProximo = pAux->getProx();
        delete pAux;
        pAux = pProximo;
    }

    pPrimeiro = nullptr;
    pUltimo = nullptr;
    tamanho = 0;
}

template <typename TL>
typename Lista<TL>::Elemento* Lista<TL>::getPrimeiro()
{
    return pPrimeiro;
}

template <typename TL>
int Lista<TL>::getTamanho()
{
    return tamanho;
}

#endif