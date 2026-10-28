#include "stdafx.hpp"
#include "Entidade.hpp"
#include "Jogador.hpp"

class Obstaculo : public Entidade
{
    protected:

        int largura;
        int altura;
        bool danoso;

    public:

        Obstaculo(int x, int y, int largura, int altura);
        ~Obstaculo();

        int getLargura();
        int getAltura();
        bool getDanoso();

        virtual void executar() = 0;

        void salvarDataBuffer();
        virtual void salvar() = 0;
        virtual void obstaculizar (Jogador *pJ);
};