#ifndef FASE_ROSA_HPP
#define FASE_ROSA_HPP

#include "Fase.hpp"

namespace Fases 
{
class Fase_Rosa : public Fase
{   
    public:

        Fase_Rosa(int numJog, bool recuperar = false);
        ~Fase_Rosa();

    protected:

        //Fase 1 só terá inimigos fáceis e médios
        void criarInimigos();
        void criarInimMedios();

        void criarObstaculos();
        void criarObstSlimes();
};
}

#endif