#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

class Projetil : public Entidade
{
    protected:

        bool ativo;

    public:

        Projetil(int x, int y, int largura, int altura, int dano);
        ~Projetil();

        void salvarDataBuffer();
        void colidir (Entidade *pEnt);
        void mover();

        void executar();
        void salvar();
};

#endif