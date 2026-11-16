#ifndef CHEFAO_HPP
#define CHEFAO_HPP

#include "Inimigo.hpp"

class ListaEntidades;
class Gerenciador_Colisoes;
class Chefao : public Inimigo
{
    private:

        ListaEntidades* pLista;
        Gerenciador_Colisoes* pGC;
        int recarga;

    public:

        Chefao(float x, float y, ListaEntidades* pLista, Gerenciador_Colisoes* pGC);
        ~Chefao();

        void executar();
        void salvar();
        void danificar (Jogador* pJog);
};

#endif