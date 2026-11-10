#ifndef INIMIGO_FACIL_HPP
#define INIMIGO_FACIL_HPP 

#include "Inimigo.hpp"

class Inim_Facil : public Inimigo
{
    private:

        /*int largura, altura;    
        short int nivel_maldade;
        float força;*/

    public:

        Inim_Facil(float x, float y);
        ~Inim_Facil();

        void salvar();
        void danificar (Jogador* pJog);
};

#endif