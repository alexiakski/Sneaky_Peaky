#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

class Projetil : public Entidade
{
    protected:

        bool ativo;
        int dano;

    public:

        Projetil(float x, float y, float largura, float altura, int dano);
        virtual ~Projetil();

        bool getAtivo() const;
        void setAtivo(bool ativo);  

        int getDano() const;

        void colidir (Entidade *pEnt);
        void mover();

        void executar();
        void salvar();
        void salvarDataBuffer();
};

#endif
