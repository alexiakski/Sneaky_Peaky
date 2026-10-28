#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

#include "stdafx.hpp"
#include "Ente.hpp"
#include "Entidade.hpp"
#include "Obstaculo.hpp"

class Gerenciador_Grafico
{
    private:

        //BiblioGrafica obj;

    public:

        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        void desenhar(Ente *pE);
};

#endif