#ifndef CHAO_HPP
#define CHAO_HPP

#include "Entidade.hpp"

class Personagem;

class Chao : public Entidade
{
    public:

        Chao(float x, float y, float largura, float altura, sf::IntRect recorte);
        ~Chao();

        void sustentar(Personagem* pP);

        void executar();
        void salvar();
};

#endif