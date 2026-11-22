#ifndef SAMURAI_HPP
#define SAMURAI_HPP

#include "Inimigo.hpp"

namespace Listas { class ListaEntidades; }
namespace Gerenciadores { class Gerenciador_Colisoes; }
namespace Entidades::Personagens
{
class Samurai : public Inimigo
{
    private:

        Listas::ListaEntidades* pLista;
        Gerenciadores::Gerenciador_Colisoes* pGC;
        int recarga;

    public:

        Samurai(float x, float y, Listas::ListaEntidades* pLista, Gerenciadores::Gerenciador_Colisoes* pGC);
        ~Samurai();

        void executar();
        void salvar();
        void danificar (Jogador* pJog);
};
}

#endif