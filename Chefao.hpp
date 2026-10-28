#ifndef CHEFAO_HPP
#define CHEFAO_HPP

#include "Inimigo.hpp"

class Chefao : public Inimigo
{
    private:

        int largura, altura;    
        short int nivel_maldade;
        //float força;

    public:

        Chefao(int x, int y, short int nivel_maldade);
        ~Chefao();

        short int getNivelMaldade();
        void setNivelMaldade(short int nivel_maldade);

        virtual void executar() = 0;
        void salvarDataBuffer();
        virtual void salvar() = 0;
        void danificar (Jogador* pJog);
};

#endif