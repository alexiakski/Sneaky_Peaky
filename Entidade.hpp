#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include "stdafx.hpp"
#include "Ente.hpp"

class Entidade : public Ente
{
    protected:

        float x, y;
        //ostream buffer; salvamento-requisito 10

    public:
    
        Entidade(float x, float y);
        virtual ~Entidade();

        float getX();
        float getY();
        //ostream getBuffer();

        virtual void executar() = 0;

        void salvarDataBuffer();
        virtual void salvar() = 0;
};

#endif