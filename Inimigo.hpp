#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Jogador.hpp"
#include "Personagem.hpp"

class Inimigo : public Personagem
{
    protected:

        int nivel_maldade;

    public:

        Inimigo(int x, int y, int largura, int altura);
        ~Inimigo();

        void salvarDataBuffer();
        void colidir (Jogador *pJog);
        void mover();

        virtual void danificar (Jogador* pJog) = 0;
        virtual void salvar() = 0;
        virtual void executar() = 0;
};

#endif