#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"

class Jogo
{
    private:

        Gerenciador_Grafico GG;    
        Jogador jog1;
    
    public:

        Jogo();
        ~Jogo();

        void executar();
};

#endif