#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"
#define MAX_VIDAS 4

namespace Entidades::Personagens
{
    class Inimigo;
class Jogador : public Personagem
{
    protected:

        int pontos;
        int direcao, quadro, contador;//para animação
        float empurraoX;

        sf::Keyboard::Key teclaCima;
        sf::Keyboard::Key teclaBaixo;
        sf::Keyboard::Key teclaEsquerda;
        sf::Keyboard::Key teclaDireita;
        //jogador 1 usa up, down, left, right e jogador 2 usa w, s, a, d

        sf::RectangleShape coracao;
        float cX;//canto da tela onde ficam os corações
    
    public:
    
        Jogador(float x, float y, int largura, int altura, int num_jog);
        virtual ~Jogador();

        void colidir (Inimigo *pIn);
        void sofrerAtaque(int dano);
        
        Jogador& operator++();
        int getPontos() const;
        
        void reposicionarJogObst(const sf::FloatRect& rectObstaculo);
        void reposicionarJogInim(const sf::FloatRect& rectInimigo);
        void setEmpurraoX(float empurraoX);

        void desenhar();
        void salvar();
        void mover();
        void executar();
};
}

#endif
