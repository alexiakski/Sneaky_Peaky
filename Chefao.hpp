#ifndef CHEFAO_HPP
#define CHEFAO_HPP

#include "Inimigo.hpp"

class Chefao : public Inimigo
{
    private:
  
        short int nivel_maldade;

    public:

        Chefao(float x, float y, float largura, float altura, short int nivel_maldade);
    public:

        Chefao(float x, float y);
        ~Chefao();

        void salvar();
        void danificar (Jogador* pJog);
};

#endif