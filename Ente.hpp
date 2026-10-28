#ifndef ENTE_HPP
#define ENTE_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>
//using namespace trabalho_tec_prog; 
class Gerenciador_Grafico;
class Ente
{
    protected:

        int id;
        static int cont;
        static Gerenciador_Grafico* pGG;
        sf::RectangleShape* pFig;//trocar quando escolher sprite

    public:

        Ente();
        virtual ~Ente();

        int getId();
        sf::RectangleShape* getFigura();

        virtual void executar() = 0;
        void desenhar();
        void static setGG(Gerenciador_Grafico *pGG);
};

#endif