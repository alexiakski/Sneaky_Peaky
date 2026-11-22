#ifndef INIM_DUENDEAZUL_HPP
#define INIM_DUENDEAZUL_HPP

#include "Inimigo.hpp"

class Inim_DuendeAzul : public Inimigo
{
    private:

        int largura, altura;    
        short int nivel_maldade;

    public:

        Inim_DuendeAzul(float x, float y);
        ~Inim_DuendeAzul();

        void salvar();
        void danificar (Jogador* pJog);
};

#endif