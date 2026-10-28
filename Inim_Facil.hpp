#ifndef INIMIGO_FACIL_HPP
#define INIMIGO_FACIL_HPP 

#include "Inimigo.hpp"

class Inim_Facil : public Inimigo
{
    private:

        int largura, altura;    
        short int nivel_maldade;
        //float força;

    public:

        Inim_Facil(int x, int y, short int nivel_maldade);
        ~Inim_Facil();

        short int getNivelMaldade();
        void setNivelMaldade(short int nivel_maldade);

        virtual void executar() = 0;
        void salvarDataBuffer();
        virtual void salvar() = 0;
        void danificar (Jogador* pJog);
};

#endif