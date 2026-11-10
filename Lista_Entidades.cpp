#include "Lista_Entidades.hpp"
#include "stdafx.hpp"

ListaEntidades::ListaEntidades() : LEs()
{

}

ListaEntidades::~ListaEntidades()
{
    limpar();
}

void ListaEntidades::incluir(Entidade* pEnt)
{
    LEs.incluir(pEnt);
}

void ListaEntidades::percorrer()
{
    Lista<Entidade>::Elemento* pAux = LEs.getPrimeiro();

    while (pAux != nullptr)
    {
        Entidade* pE = pAux->getInfo();
        pE->executar();             //polimorfismo: chama o executar() do Jogador, Inimigo, ...
        pAux = pAux->getProx();
    }
}

void ListaEntidades::desenhar()
{
    Lista<Entidade>::Elemento* pAux = LEs.getPrimeiro();

    while (pAux != nullptr)
    {
        pAux->getInfo()->desenhar();
        pAux = pAux->getProx();
    }
}

void ListaEntidades::limpar()
{
    Lista<Entidade>::Elemento* pAux = LEs.getPrimeiro();

    while (pAux != nullptr)
    {
        delete pAux->getInfo();     //a ListaEntidades é dona das entidades
        pAux = pAux->getProx();
    }

    LEs.limpar();                   //depois apaga os elementos
}

int ListaEntidades::getTamanho()
{
    return LEs.getTamanho();
}