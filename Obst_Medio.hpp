#ifndef OBST_MEDIO_HPP
#define OBST_MEDIO_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos 
{
class Obst_Medio : public Obstaculo
{
    private:

        float forca;

    public:

        Obst_Medio(float x, float y,float largura, float altura, float forca);
        ~Obst_Medio();

        virtual void executar();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif