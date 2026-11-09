#ifndef OBSTACULO_HPP
#define OBSTACULO_HPP

#include "stdafx.hpp"
#include "Entidade.hpp"
#include "Jogador.hpp"

class Obstaculo : public Entidade
{
    protected:

        bool danoso;

    public:

        Obstaculo(float x, float y, float largura, float altura, bool danoso = false);
        virtual ~Obstaculo();

        bool getDanoso();
        void setDanoso(bool danoso);

        virtual void executar() = 0;

        void salvarDataBuffer();
        virtual void salvar() = 0;
        virtual void obstaculizar (Jogador *pJ);
};

#endif
