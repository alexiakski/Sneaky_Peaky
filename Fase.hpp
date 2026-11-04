#ifndef FASE_HPP
#define FASE_HPP

#include "Ente.hpp"
#include "Lista_Entidades.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Jogador.hpp"

class Fase : public Ente
{
    protected:
        
        ListaEntidades lista_ents;
        Gerenciador_Colisoes GC;
        Jogador *pJog1;

        const int maxInimFaceis;

    public:

        Fase();
        virtual ~Fase();

        virtual void executar();

    protected:

        void criarInimFaceis();
        void criarPlataformas();
        void criarJogadores();
        void criarCenario();
        void setFundo (const std::string& caminho, sf::IntRect ladrilho);
        
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;

};

#endif