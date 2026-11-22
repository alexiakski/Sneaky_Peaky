#ifndef SAMURAI_HPP
#define SAMURAI_HPP

#include "Inimigo.hpp"

class ListaEntidades;
class Gerenciador_Colisoes;
class Samurai : public Inimigo
{
    private:

        ListaEntidades* pLista;
        Gerenciador_Colisoes* pGC;
        int recarga;

    public:

        Samurai(float x, float y, ListaEntidades* pLista, Gerenciador_Colisoes* pGC);
        ~Samurai();

        void executar();
        void salvar();
        void danificar (Jogador* pJog);
};

#endif