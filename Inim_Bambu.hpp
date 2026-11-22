#ifndef INIM_BAMBU_HPP
#define INIM_BAMBU_HPP 

#include "Inimigo.hpp"

namespace Entidades::Personagens 
{
class Inim_Bambu : public Inimigo
{

    public:

        Inim_Bambu(float x, float y);
        ~Inim_Bambu();

        void salvar();
        void danificar (Jogador* pJog);
};
}

#endif