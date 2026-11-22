#ifndef FASE_GELO_HPP
#define FASE_GELO_HPP

#include "Fase.hpp"

class Fase_Gelo : public Fase
{
    public:

        Fase_Gelo(int numJog);
        ~Fase_Gelo();

    protected:

        //Fase 2 só terá inimigos fáceis e chefe   
        void criarInimigos();
        void criarInimChefes(const sf::Vector2f posicoes[]);

        void criarObstaculos();
        void criarPlataformas();
        void criarObstaculosDificeis();

};

#endif