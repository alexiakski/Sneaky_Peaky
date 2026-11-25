#ifndef OBST_SLIME_HPP
#define OBST_SLIME_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos 
{
class Obst_Slime : public Obstaculo
{
    private:

        float forca;

    public:

        Obst_Slime(float x, float y,float largura, float altura, float forca);
        ~Obst_Slime();

        virtual void executar();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif