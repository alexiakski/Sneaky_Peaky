#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "Obstaculo.hpp"

//class Personagem;

class Plataforma : public Obstaculo
{
    private:

        int largura, altura;   
        float velocidadeY;

    public:

        Plataforma(int x, int y, int largura, int altura, float velocidadeY = 0);
        ~Plataforma();

        int getLargura() const;
        int getAltura() const;

        virtual void executar() = 0;
        void salvarDataBuffer();
        virtual void salvar() = 0;
        void obstaculizar (Jogador *pJ);
};

#endif