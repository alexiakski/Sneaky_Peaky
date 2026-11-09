#ifndef INIMIGO_MEDIO_HPP
#define INIMIGO_MEDIO_HPP

#include "Inimigo.hpp"

class Inim_Medio : public Inimigo
{
    private:

        int largura, altura;    
        short int nivel_maldade;
        //float força;

    public:

        Inim_Medio(float x, float y);
        ~Inim_Medio();

        void salvar();
        void danificar (Jogador* pJog);
};

#endif