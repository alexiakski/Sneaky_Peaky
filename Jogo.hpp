#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
#include "Fase.hpp"
#include "Menu.hpp"

class Jogo
{
    private:

        Gerenciador_Grafico GG;
        Menu menu;
        Fase *pFase;
            
    public:

        Jogo();
        ~Jogo();

        void executar();
};

#endif