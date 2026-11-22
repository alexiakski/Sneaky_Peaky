#ifndef FASE_ROSA_HPP
#define FASE_ROSA_HPP

#include "Fase.hpp"

class Fase_Rosa : public Fase
{   
    public:

        Fase_Rosa(int numJog);
        ~Fase_Rosa();

    protected:

        //Fase 1 só terá inimigos fáceis e médios
        void criarInimigos();
        void criarInimMedios(const sf::Vector2f posicoes[], int total);

        void criarObstaculos();
        void criarPlataformas();
        void criarObstaculosMedios();
};

#endif