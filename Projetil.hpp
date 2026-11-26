#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "Entidade.hpp"

namespace Entidades::Personagens {class Samurai;}
namespace Entidades 
{
class Projetil : public Entidade
{
    protected:

        int dano;
        float velocidade;
        Personagens::Samurai* pAtirador;

    public:

        Projetil(float x, float y, float largura, float altura, int dano, float velocidade, Personagens::Samurai* pAtirador);
        virtual ~Projetil();

        Personagens::Samurai* getAtirador() const;

        int getDano() const;

        void colidir (Entidade *pEnt);
        void mover();

        void executar();
        void salvar();
};
}

#endif
