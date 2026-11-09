#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"

class Inimigo;
class Jogador : public Personagem
{
    protected:

        int pontos;
        float velocidadeY;

        int direcao, quadro, contador;//para animação

        sf::Keyboard::Key teclaCima;
        sf::Keyboard::Key teclaBaixo;
        sf::Keyboard::Key teclaEsquerda;
        sf::Keyboard::Key teclaDireita;
        //jogador 1 usa up, down, left, right e jogador 2 usa w, s, a, d
    
    public:
    
        Jogador(float x, float y, int largura, int altura, int num_jog);
        virtual ~Jogador();

        void colidir (Inimigo *pIn); //implementar com GC
        
        //usar na classe objeto
        //void reposicionar(const sf::FloatRect& rectObstaculo);

        void salvar();
        void mover();
        void executar();
};

#endif
