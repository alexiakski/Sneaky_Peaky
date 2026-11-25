#include "stdafx.hpp"
#include "Fase_Rosa.hpp"
#include "Inim_DuendeAzul.hpp"
#include "Obst_Slime.hpp"
#include "Plataforma.hpp"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;
namespace Fases 
{
Fase_Rosa::Fase_Rosa(int numJog, bool recuperar) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(176, 0, 160, 64));

    criarChao(sf::IntRect(16, 144, 16, 48));//chão rosa

    if (recuperar)
        Fase::recuperar();
    
    else
    {
        criarJogadores(numJog);
        criarCenario();
    }
}

Fase_Rosa::~Fase_Rosa()
{

}

void Fase_Rosa::criarInimigos()
{    
    criarInimFaceis();//comum às duas fases (implementado na Fase)
    criarInimMedios();//médio exclusivo da fase 1
}

void Fase_Rosa::criarInimMedios()
{
    int quantidade = sortearQuant(MIN_INIMIGOS, MAX_INIMIGOS);  
    for (int i = 0; i < quantidade; i++)
    {
        Inim_DuendeAzul* pI = new Inim_DuendeAzul(0,0);
        posicionarEmPlataforma(pI);
        lista_ents.incluir(pI);
        GC.incluirInimigo(pI);
    }
}

void Fase_Rosa::criarObstaculos()
{
    criarObstSlimes();
}

void Fase_Rosa::criarObstSlimes()
{
    int quantidade = sortearQuant(MIN_OBSTACULOS, MAX_OBSTACULOS);
    
    for (int i = 0; i < quantidade; i++)
    {
        Obst_Slime* pO = new Obst_Slime(0, 0, 30, 30, 9);

        if (i % 2 == 0)//alterna
            posicionarEmPlataforma(pO);
        else
            posicionarNoChao(pO);

        lista_ents.incluir(pO);
        GC.incluirObstaculo(pO);
    }
}
}