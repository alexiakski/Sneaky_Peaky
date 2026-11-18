#include "stdafx.hpp"
#include "Fase_Rosa.hpp"
#include "Inim_DuendeAzul.hpp"
#include "Obst_Medio.hpp"
#include "Plataforma.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_one::Fase_one(int numJog) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(176, 0, 160, 64));

    criarJogadores(numJog);
    criarChao(sf::IntRect(16, 144, 16, 48));//chão rosa
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
        sf::Vector2f(40, 515),
        sf::Vector2f(240, 515),
        sf::Vector2f(440, 515),
        sf::Vector2f(630, 515)
    };

    const sf::Vector2f posMedios1[] =
    {
        sf::Vector2f(130, 507),
        sf::Vector2f(330, 507),
        sf::Vector2f(530, 507)
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
        GC.incluirInimigo(pI);
    }
}

void Fase_one::criarObstaculos()
{
    criarObstaculosMedios();
}

void Fase_one::criarObstaculosMedios()
{
    const sf::Vector2f posicoes[NUM_OBST_SEGUROS] =
    {
        sf::Vector2f(90, 522),
        sf::Vector2f(190, 522),
        sf::Vector2f(390, 522),
        sf::Vector2f(580, 522),
        sf::Vector2f(720, 522)
    };
    
    for (int i = 0; i < NUM_OBST_SEGUROS; i++)
    {
        Obst_Medio* pO = new Obst_Medio(posicoes[i].x, posicoes[i].y, 30, 30, 1);
        lista_ents.incluir(pO);
        GC.incluirObstaculo(pO);
    }
}