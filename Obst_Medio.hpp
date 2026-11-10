#ifndef OBST_DIFICIL_HPP
#define OBST_DIFICIL_HPP

#include "Obstaculo.hpp"

class Obst_Medio : public Obstaculo
{
    private:

        short int danosidade;

    public:

        Obst_Medio(float x, float y,float largura, float altura, short int danosidade);
        ~Obst_Medio();

        short int getDanosidade();
        void setDanosidade(short int danosidade);

        virtual void executar() = 0;
        void salvarDataBuffer();
        virtual void salvar() = 0;
        void obstaculizar (Jogador *pJ);
};

#endif