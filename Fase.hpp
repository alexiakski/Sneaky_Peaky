#ifndef FASE_HPP
#define FASE_HPP

#include "Ente.hpp"
#include "Lista_Entidades.hpp"
#include "Gerenciador_Colisoes.hpp"

class Fase : public Ente
{
    protected:
        
        ListaEntidades lista_ents;
        Gerenciador_Colisoes GC;

    public:

        Fase();
        ~Fase();

        virtual void executar() = 0;

    protected:

        void criarInimFaceis();

        void criarJogadores();
        void criarCenario();
        
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;

};

#endif