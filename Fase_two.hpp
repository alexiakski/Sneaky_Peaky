#ifndef FASE_TWO_HPP
#define FASE_TWO_HPP

#include "Fase.hpp"

class Fase_two : public Fase
{
   private: 
   
    const int maxInimFaceis;
    const int maxInimMedios;
    const int maxObsts;
   
    public:

        Fase_two();
        ~Fase_two();

        void executar();

    protected:

        void criarInimFaceis();
        void criarInimChefes();

        void criarPlataformas();
        void criarObstaculosMedios();
        void criarObstaculosDificeis();
};

#endif