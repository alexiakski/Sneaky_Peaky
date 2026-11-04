#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Jogador.hpp"
#include "Personagem.hpp"

class Inimigo : public Personagem
{
    protected:

        int nivel_maldade;

    public:

        Inimigo(float x, float y, int largura, int altura, int num_vidas, int nivel_maldade);
        ~Inimigo();

        int getNivelMaldade();
        void setNivelMaldade(int nivel_maldade);

        void salvarDataBuffer();
        //void colidir (Jogador *pJog);
        void mover();
        void executar();

        virtual void danificar (Jogador* pJog) = 0;
        virtual void salvar() = 0;
};

#endif