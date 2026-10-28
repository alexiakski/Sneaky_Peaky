#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Inimigo.hpp"
#include "Personagem.hpp"

class Jogador : public Personagem
{
    protected:

        int pontos;
    
    public:
        Jogador(int x, int y, int largura, int altura);
        ~Jogador();

        void colidir (Inimigo *pIn);

        void salvar();
        void mover();
        void executar();
};

#endif