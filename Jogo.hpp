#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
#include "Fase.hpp"
#include "Menu.hpp"

class Jogo
{
    private:

        Gerenciadores::Gerenciador_Grafico GG;
        Menu menu;
        Fases::Fase *pFase;
            
    public:

        Jogo();
        ~Jogo();

        void executar();
};

#endif