#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"

class Inimigo;
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