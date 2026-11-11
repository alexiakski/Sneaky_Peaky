#include "stdafx.hpp"
#include "Fase_Rosa.hpp"
#include "Inim_DuendeAzul.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_one::Fase_one() : Fase()
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
    //inimigos vão ter opções de posicionamento no mapa
    const sf::Vector2f posFaceis[] =
    {
        sf::Vector2f(150, 480),
        sf::Vector2f(400, 480),
        //sf::Vector2f(650, 480),
        sf::Vector2f(250, 300),
        sf::Vector2f(550, 300)
    };

    const sf::Vector2f posMedios1[] =
    {
        //sf::Vector2f(100, 150),
        sf::Vector2f(370, 150),
        sf::Vector2f(640, 150),
        sf::Vector2f(500, 420)
    };
    
    criarInimFaceis(posFaceis, sizeof(posFaceis) / sizeof(posFaceis[0]));//comum às duas fases (implementado na Fase)
    criarInimMedios(posMedios1, sizeof(posMedios1) / sizeof(posMedios1[0]));//médio exclusivo da fase 1
}

void Fase_one::criarInimMedios(const sf::Vector2f posicoes[], int total)
{
    int quantidade = 3 + rand() % (total - 3 + 1);  
    for (int i = 0; i < quantidade; i++)
    {
        Inim_Medio* pI = new Inim_Medio(posicoes[i].x, posicoes[i].y);
        lista_ents.incluir(pI);
        //GC.incluirInimigo(pI);
    }
}

void Fase_one::criarObstaculos()
{
    criarObstaculosMedios();
}

void Fase_one::criarObstaculosMedios()
{
    for (int i = 0; i < NUM_OBST_SEGUROS; i++)
    {
        //Obst_Medio* pO = new Obst_Medio(...);  lista_ents.incluir(pO);  GC.incluirObstaculo(pO);
    }
}