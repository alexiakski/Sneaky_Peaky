#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"

class Personagem : public Entidade 
{
    protected:

        int num_vidas;

    public:

        Personagem(int x, int y, int largura, int altura, int num_vidas);
        ~Personagem();

        int getNumVidas();
        void setNumVidas(int num_vidas);

        void salvarDataBuffer();

        virtual void salvar() = 0;
        virtual void mover() = 0;
        virtual void executar() = 0;
};

#endif