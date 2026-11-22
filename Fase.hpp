#ifndef FASE_HPP
#define FASE_HPP

#include "Ente.hpp"
#include "Lista_Entidades.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Jogador.hpp"

#define MIN_INIMIGOS 3
#define MAX_INIMIGOS 4
#define NUM_PLATAFORMAS 11

namespace Fases
{
class Fase : public Ente
{
    protected:
        
        Listas::ListaEntidades lista_ents;
        Gerenciadores::Gerenciador_Colisoes GC;
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;

    public:

        Fase();
        virtual ~Fase();
        virtual void executar();
        bool getFimDeJogo() const;
        bool getVitoria() const;
        int getPontos() const;

    protected:

        void criarInimFaceis();
        int sortearQuantInimigos() const;
        void criarPlataformas();
        void criarJogadores(int numJog);
        void criarCenario();
        void setFundo (const std::string& caminho, sf::IntRect ladrilho);
        void criarChao(sf::IntRect recorte);
        bool plataformaOcupada[NUM_PLATAFORMAS];
        void posicionarEmPlataforma(Entidades::Entidade* pE);
        
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;

};
}

#endif