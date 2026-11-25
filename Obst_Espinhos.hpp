#ifndef OBST_ESPINHOS_HPP
#define OBST_ESPINHOS_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos 
{
class Obst_Espinhos : public Obstaculo
{
    private:
      
        short int danosidade;

    public:

        Obst_Espinhos(float x, float y, float largura, float altura, short int danosidade);
        ~Obst_Espinhos();

        short int getDanosidade() const;
        void setDanosidade(short int danosidade);

        virtual void executar();
        void salvarDataBuffer();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif