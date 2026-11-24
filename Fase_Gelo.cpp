#include "stdafx.hpp"
#include "Fase_Gelo.hpp"
#include "Samurai.hpp"
#include "Obst_Dificil.hpp"
#include "Plataforma.hpp"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
namespace Fases 
{
Fase_Gelo::Fase_Gelo(int numJog, bool recuperar) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(0, 336, 160, 48));//fundo neve

    criarChao(sf::IntRect(16, 192, 16, 48));//chão neve

    if (recuperar)
        Fase::recuperar();
    
    else
    {
        criarJogadores(numJog);
        criarCenario();
    }
}

Fase_Gelo::~Fase_Gelo()
{

}

void Fase_Gelo::criarInimigos()
{    
    criarInimFaceis();//comum às duas fases (implementado na Fase)
    criarInimChefes();//chefão exclusivo da fase 2
}

void Fase_Gelo::criarInimChefes()
{
    int quantidade = sortearQuant(MIN_INIMIGOS, MAX_INIMIGOS);

    for (int i = 0; i < quantidade; i++)
    {
        Samurai* pC = new Samurai(0, 0, &lista_ents, &GC);
        posicionarEmPlataforma(pC);
        lista_ents.incluir(pC);
        GC.incluirInimigo(pC);
    }
}

void Fase_Gelo::criarObstaculos()
{
    criarObstaculosDificeis();
}

void Fase_Gelo::criarObstaculosDificeis()
{
    int quantidade = sortearQuant(MIN_OBSTACULOS, MAX_OBSTACULOS);
    
    for (int i = 0; i < quantidade; i++)
    {
        Obst_Dificil* pO = new Obst_Dificil(0, 0, 30, 30, 1);

        if (i % 2 == 0)
            posicionarEmPlataforma(pO);
        else
            posicionarNoChao(pO);

        lista_ents.incluir(pO);
        GC.incluirObstaculo(pO);
    }
}
}