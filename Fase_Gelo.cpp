#include "stdafx.hpp"
#include "Fase_Gelo.hpp"
#include "Samurai.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_two::Fase_two() : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(176, 0, 160, 64));//mudar fundo

    criarJogadores();
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
        sf::Vector2f(150, 480),
        sf::Vector2f(400, 480),
        //sf::Vector2f(650, 480),
        sf::Vector2f(250, 300),
        sf::Vector2f(550, 300)
    };

    const sf::Vector2f posChefes1[] =
    {
        sf::Vector2f(70, 90)
    };
    
    criarInimFaceis(posFaceis, sizeof(posFaceis) / sizeof(posFaceis[0]));//comum às duas fases (implementado na Fase)
    criarInimChefes(posChefes1);//chefão exclusivo da fase 2
}

void Fase_two::criarInimChefes(const sf::Vector2f posicoes[])
{
    Chefao* pC = new Chefao(posicoes[0].x, posicoes[0].y);//só um chefão por fase
    lista_ents.incluir(pC);
    //GC.incluirInimigo(pC);
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