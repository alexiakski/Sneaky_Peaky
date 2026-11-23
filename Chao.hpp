#ifndef CHAO_HPP
#define CHAO_HPP

#include "Entidade.hpp"

namespace Entidades
{
    namespace Personagens {class Personagem;}
class Chao : public Entidade
{
    public:

        Chao(float x, float y, float largura, float altura, sf::IntRect recorte);
        ~Chao();

        void sustentar(Personagens::Personagem* pP);

        void executar();
        void salvar();
};
}

#endif