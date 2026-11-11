#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"

class Personagem : public Entidade 
{
    protected:

        int num_vidas;
        float velocidadeY;
        bool chao;

    public:

        Personagem(float x, float y, int largura, int altura, int num_vidas);
        virtual ~Personagem();

        int getNumVidas();
        void setNumVidas(int num_vidas);

        void aplicarGravidade();
        void reposicionar(const sf::FloatRect &rect);

        virtual void salvarDataBuffer();

        virtual void salvar() = 0;
        virtual void mover() = 0;
        virtual void executar() = 0;
};

#endif