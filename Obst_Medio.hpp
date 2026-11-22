#ifndef OBST_MEDIO_HPP
#define OBST_MEDIO_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos 
{
class Obst_Medio : public Obstaculo
{
    private:

        short int danosidade;

    public:

        Obst_Medio(float x, float y,float largura, float altura, short int danosidade);
        ~Obst_Medio();

        short int getDanosidade() const;
        void setDanosidade(short int danosidade);

        virtual void executar();
        void salvarDataBuffer();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif