#ifndef CHEFAO_HPP
#define CHEFAO_HPP

#include "Inimigo.hpp"

class Chefao : public Inimigo
{

    public:

        Chefao(float x, float y);
        ~Chefao();

        void salvar();
        void danificar (Jogador* pJog);
};

#endif