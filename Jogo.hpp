#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
#include "Fase.hpp"

class Jogo
{
    private:

        Gerenciador_Grafico GG;    
        Fase *pFase;
            
    public:

        Jogo();
        ~Jogo();

        void executar();
};

#endif