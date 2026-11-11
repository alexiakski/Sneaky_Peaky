#ifndef FASE_TWO_HPP
#define FASE_TWO_HPP

#include "Fase.hpp"

class Fase_two : public Fase
{
    public:

        Fase_two();
        ~Fase_two();

    protected:

        //Fase 2 só terá inimigos fáceis e chefe   
        void criarInimigos();
        void criarInimChefes(const sf::Vector2f posicoes[]);

        void criarObstaculos();
        void criarPlataformas();
        void criarObstaculosDificeis();

};

#endif