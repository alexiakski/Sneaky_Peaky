#ifndef LISTA_ENT_HPP
#define LISTA_ENT_HPP

#include "Lista.hpp"
#include "Entidade.hpp"
#include "Ente.hpp"

template <typename TE>
class ListaEntidades
{
    private:

        Lista::Elemento *pInicio;
        Lista::Elemento *pFim;

        Lista <Entidade> LEs;

    public:

        ListaEntidades();
        ~ListaEntidades();

        void incluir (Ente *pEnt);
        void limpar();
        void imprimir();
        void percorrer();
};

#endif