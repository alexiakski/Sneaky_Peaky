#ifndef FASE_ONE_HPP
#define FASE_ONE_HPP

#include "Fase.hpp"

class Fase_one : public Fase
{
   private: 
   
   const int maxInimFaceis; 
   const int maxInimMedios;
   
    public:

        Fase_one();
        ~Fase_one();

        void executar();

    protected:

        void criarInimMedios();
        void criarInimChefes();

        void criarPlataformas();
        void criarObstaculosMedios();
        void criarObstaculosDificeis();
};

#endif