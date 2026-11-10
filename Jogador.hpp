#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"

class Inimigo;
class Jogador : public Personagem
{
    protected:

        int pontos;
    
    public:
    
        Jogador(float x, float y, int largura, int altura);
        virtual ~Jogador();

        void colidir (Inimigo *pIn); //implementar com GC
        void sofreAtaque(int dano);
        
        //usar na classe objeto
        //void reposicionar(const sf::FloatRect& rectObstaculo);

        void salvar();
        void mover();
        void executar();
};

#endif