#ifndef LISTA_ENT_HPP
#define LISTA_ENT_HPP

#include "Lista.hpp"
#include "Entidade.hpp"
#include "Ente.hpp"

class ListaEntidades
{
    private:

        //Lista::Elemento *pInicio;
        //Lista::Elemento *pFim;

        Lista <Entidade> LEs;

    public:

        ListaEntidades();
        ~ListaEntidades();

        void incluir (Entidade *pEnt);
        void limpar();
        void percorrer();
        void desenhar();
        int getTamanho();
};

#endif