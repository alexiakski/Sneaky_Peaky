#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "Obstaculo.hpp"

//class Personagem;

class Plataforma : public Obstaculo
{
    private:

        float velocidadeY;

    public:

        Plataforma(float x, float y, float largura, float altura, float velocidadeY = 0);
        ~Plataforma();

        int getLargura() const;
        int getAltura() const;

        virtual void executar();
        void salvarDataBuffer();
        virtual void salvar();
        void obstaculizar (Jogador *pJ);
};

#endif