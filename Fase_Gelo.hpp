#ifndef FASE_GELO_HPP
#define FASE_GELO_HPP

#include "Fase.hpp"

namespace Fases 
{
class Fase_Gelo : public Fase
{
    public:

        Fase_Gelo(int numJog);
        ~Fase_Gelo();

    protected:

        //Fase 2 só terá inimigos fáceis e chefes 
        void criarInimigos();
        void criarInimChefes();

        void criarObstaculos();
        void criarObstaculosDificeis();

};
}

#endif