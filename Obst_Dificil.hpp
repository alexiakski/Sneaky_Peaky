#ifndef OBST_DIFICIL_HPP
#define OBST_DIFICIL_HPP

#include "Obstaculo.hpp"

class Obst_Dificil : public Obstaculo
{
    private:

        int largura, altura;        
        short int danosidade;

    public:

        Obst_Dificil(int x, int y, short int danosidade);
        ~Obst_Dificil();

        short int getDanosidade();
        void setDanosidade(short int danosidade);

        virtual void executar() = 0;
        void salvarDataBuffer();
        virtual void salvar() = 0;
        void obstaculizar (Jogador *pJ);
};

#endif