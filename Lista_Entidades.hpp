#ifndef LISTA_ENT_HPP
#define LISTA_ENT_HPP

#include "Lista.hpp"
#include "Entidade.hpp"
#include "Ente.hpp"

namespace Listas
{
class ListaEntidades
{
    private:

        Lista <Entidades::Entidade> LEs;

    public:

        ListaEntidades();
        ~ListaEntidades();

        void incluir (Entidades::Entidade *pEnt);
        void limpar();
        void percorrer();
        void desenhar();
        int getTamanho() const;
        void salvar();
};
}

#endif