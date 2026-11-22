#ifndef INIM_DUENDEAZUL_HPP
#define INIM_DUENDEAZUL_HPP

#include "Inimigo.hpp"

namespace Entidades::Personagens 
{
class Inim_DuendeAzul : public Inimigo
{
    private:

        int largura, altura, contador;    
        short int nivel_maldade;

    public:

        Inim_DuendeAzul(float x, float y);
        ~Inim_DuendeAzul();

        void salvar();
        void danificar (Jogador* pJog);
        void executar();
};
}

#endif