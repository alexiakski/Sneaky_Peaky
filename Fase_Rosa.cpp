#include "stdafx.hpp"
#include "Fase_Rosa.hpp"
#include "Inim_DuendeAzul.hpp"
#include "Obst_Medio.hpp"
#include "Plataforma.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_Rosa::Fase_Rosa(int numJog) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(176, 0, 160, 64));

    criarJogadores(numJog);
    criarChao(sf::IntRect(16, 144, 16, 48));//chão rosa
    criarCenario();
    criarInimigos();
}

Fase_Rosa::~Fase_Rosa()
{

}

void Fase_Rosa::criarInimigos()
{
    //inimigos vão ter opções de posicionamento no mapa
    /*const sf::Vector2f posFaceis[] =
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
    };*/
    
    criarInimFaceis();//comum às duas fases (implementado na Fase)
    criarInimMedios();//médio exclusivo da fase 1
}

void Fase_Rosa::criarInimMedios()
{
    int quantidade = sortearQuantInimigos();  
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
    criarObstaculosMedios();
}

void Fase_Rosa::criarObstaculosMedios()
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