#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "Obstaculo.hpp"

namespace Entidades::Obstaculos
{
class Plataforma : public Obstaculo
{
    private:

        float velocidadeY;

    public:

        Plataforma(float x, float y, float largura, float altura, float velocidadeY = 0);
        ~Plataforma();

        int getLargura() const;
        int getAltura() const;

        virtual void executar();
        virtual void salvar();
        void obstaculizar (Personagens::Jogador *pJ);
};
}

#endif