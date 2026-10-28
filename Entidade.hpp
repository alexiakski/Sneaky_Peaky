#include "stdafx.hpp"
#include "Ente.hpp"

class Entidade : public Ente
{
    protected:

        int x;
        int y;
        ostream buffer;

    public:
    
        Entidade(int x, int y);
        virtual ~Entidade();

        int getX();
        int getY();
        ostream getBuffer();

        virtual void executar() = 0;

        void salvarDataBuffer();
        virtual void salvar() = 0;
};