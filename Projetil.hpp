#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

namespace Entidades 
{
class Projetil : public Entidade
{
    protected:

        int dano;
        float velocidade;

    public:

        Projetil(float x, float y, float largura, float altura, int dano, float velocidade);
        virtual ~Projetil();

        int getDano() const;

        void colidir (Entidade *pEnt);
        void mover();

        void executar();
        void salvar();
};
}

#endif
