#ifndef OBST_DIFICIL_HPP
#define OBST_DIFICIL_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos 
{
class Obst_Dificil : public Obstaculo
{
    private:
      
        short int danosidade;

    public:

        Obst_Dificil(float x, float y, float largura, float altura, short int danosidade);
        ~Obst_Dificil();

        short int getDanosidade() const;
        void setDanosidade(short int danosidade);

        virtual void executar();
        void salvarDataBuffer();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif