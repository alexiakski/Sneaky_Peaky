#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

namespace Entidades 
{
class Projetil : public Entidade
{
    protected:

        int dano;

    public:

        Projetil(float x, float y, float largura, float altura, int dano);
        virtual ~Projetil();

        int getDano() const;

        void colidir (Entidade *pEnt);
        void mover();

        void executar();
        void salvar();
        void salvarDataBuffer();
};
}

#endif
