#include "stdafx.hpp"
#include "Fase_one.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_one::Fase_one() : Fase(), maxInimMedios(6)
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(176, 0, 160, 64));

    criarJogadores();
    criarCenario();
    criarInimigos();
}

Fase_one::~Fase_one()
{

}

void Fase_one::criarInimigos()
{
    criarInimFaceis();//comum às duas fases (implementado na Fase)
    criarInimMedios();//médio exclusivo da fase 1
    criarInimChefes();//chefão exclusivo da fase 1
}

void Fase_one::criarInimMedios()
{
    int quantidade = 3 + rand() % (maxInimMedios - 3 + 1);
    for (int i = 0; i < quantidade; i++)
    {
        //Tengu* pI = new Tengu(...);  lista_ents.incluir(pI);  GC.incluirInimigo(pI);
    }
}

void Fase_one::criarInimChefes()
{
   
}

void Fase_one::criarObstaculos()
{
    criarObstaculosSeguros();
}

void Fase_one::criarObstaculosSeguros()
{
    for (int i = 0; i < NUM_OBST_SEGUROS; i++)
    {
        //Obst_Medio* pO = new Obst_Medio(...);  lista_ents.incluir(pO);  GC.incluirObstaculo(pO);
    }
}

void Fase_one::criarObstaculosDanosos()
{
    for (int i = 0; i < NUM_OBST_DANOSOS; i++)
    {
        //Obst_Danoso* pO = new Obst_Danoso(...);  lista_ents.incluir(pO);  GC.incluirObstaculo(pO);
    }
}