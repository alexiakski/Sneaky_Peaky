#include "stdafx.hpp"
#include "Gerenciador_Grafico.hpp"
#include "SFML/Graphics.hpp"
//using namespace trabalho_tec_prog; 

class Ente
{
    protected:

        int id;
        static Gerenciador_Grafico* pGG;
        sf::Drawable *pFig;

    public:

        Ente(int id, sf::Drawable *pFig);
        virtual ~Ente();

        int getId();
        sf::Drawable* getFigura();

        virtual void executar() = 0;
        void desenhar();
        void static setGG (Gerenciador_Grafico *pGG);
};