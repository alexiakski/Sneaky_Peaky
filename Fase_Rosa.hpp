#ifndef FASE_ONE_HPP
#define FASE_ONE_HPP

#include "Fase.hpp"

class Fase_one : public Fase
{   
    public:

        Fase_one();
        ~Fase_one();

    protected:

        //Fase 1 só terá inimigos fáceis e médios
        void criarInimigos();
        void criarInimMedios(const sf::Vector2f posicoes[], int total);

        void criarObstaculos();
        void criarPlataformas();
        void criarObstaculosMedios();
};

#endif