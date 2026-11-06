#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Jogador.hpp"
#include "Personagem.hpp"

class Inimigo : public Personagem
{
    protected:

        int nivel_maldade;

    public:

        Inimigo(float x, float y, float largura, float altura, int nivel_maldade = 1);
        virtual ~Inimigo();

        int getNivelMaldade() const;
        void setNivelMaldade(int nivel_maldade);

        void colidir (Jogador *pJog);
        void mover();

        virtual void danificar (Jogador* pJog) = 0;
        virtual void salvar() = 0;
        virtual void executar() = 0;

        void salvarDataBuffer();
};

#endif