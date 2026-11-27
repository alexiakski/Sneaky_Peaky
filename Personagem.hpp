#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"

namespace Entidades::Personagens
{
class Personagem : public Entidade 
{
    protected:

        int num_vidas;
        float velocidadeY;
        bool chao;
        int invencivel;//para não levar danos seguidos

    public:

        Personagem(float x, float y, int largura, int altura, int num_vidas);
        virtual ~Personagem();

        int getNumVidas() const;
        void setNumVidas(int num_vidas);

        float getVelocidadeY() const;
        void setVelocidadeY(float velocidadeY);

        void aplicarGravidade();
        void reposicionar(const sf::FloatRect &rect);

        Personagem& operator-=(int dano);//sobrecarga de operadores

        void atualizarInvincibilidade();

        void salvarDataBuffer();

        virtual void salvar() = 0;
        virtual void mover() = 0;
        virtual void executar() = 0;
};
}

#endif