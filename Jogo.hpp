#ifndef JOGO_HPP
#define JOGO_HPP

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"

class Jogo
{
    private:

        Jogador pJog1;
        Gerenciador_Grafico GG;
    
    public:

        Jogo();
        ~Jogo();

        void executar();
};

#endif