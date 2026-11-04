#ifndef FASE_ONE_HPP
#define FASE_ONE_HPP

#include "Fase.hpp"

class Fase_one : public Fase
{
   private: 
    
        const int maxInimMedios;
   
    public:

        Fase_one();
        ~Fase_one();

    protected:

        void criarInimigos();
        void criarInimMedios();
        void criarInimChefes();

        void criarObstaculos();
        void criarPlataformas();
        void criarObstaculosSeguros();
        void criarObstaculosDanosos();
};

#endif