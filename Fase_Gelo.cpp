#include "stdafx.hpp"
#include "Fase_Gelo.hpp"
#include "Samurai.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_two::Fase_two(int numJog) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(0, 336, 160, 48));//fundo neve

    criarJogadores(numJog);
    criarChao(sf::IntRect(16, 192, 16, 48));//chão neve
    criarCenario();
    criarInimigos();
}

Fase_two::~Fase_two()
{

}

void Fase_two::criarInimigos()
{
    //inimigos vão ter opções de posicionamento no mapa
    const sf::Vector2f posFaceis[] =
    {
        sf::Vector2f(200, 515),
        sf::Vector2f(330, 515),
        sf::Vector2f(460, 515),
        sf::Vector2f(590, 515)
    };

    const sf::Vector2f posChefes1[] =
    {
        sf::Vector2f(20, 520)
    };
    
    criarInimFaceis(posFaceis, sizeof(posFaceis) / sizeof(posFaceis[0]));//comum às duas fases (implementado na Fase)
    criarInimChefes(posChefes1);//chefão exclusivo da fase 2
}

void Fase_two::criarInimChefes(const sf::Vector2f posicoes[])
{
    Chefao* pC = new Chefao(posicoes[0].x, posicoes[0].y, &lista_ents, &GC);//só um chefão por fase
    lista_ents.incluir(pC);
    GC.incluirInimigo(pC);
}

void Fase_two::criarObstaculos()
{
    criarObstaculosDificeis();
}

void Fase_two::criarObstaculosDificeis()
{
    for (int i = 0; i < NUM_OBST_DANOSOS; i++)
    {
        //Obst_Danoso* pO = new Obst_Danoso(...);  lista_ents.incluir(pO);  GC.incluirObstaculo(pO);
    }
}