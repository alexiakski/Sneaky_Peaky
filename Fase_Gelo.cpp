#include "stdafx.hpp"
#include "Fase_Gelo.hpp"
#include "Samurai.hpp"
#include "Obst_Dificil.hpp"
#include "Plataforma.hpp"

#define NUM_OBST_SEGUROS 5
#define NUM_OBST_DANOSOS 4

Fase_Gelo::Fase_Gelo(int numJog) : Fase()
{
    setTextura ("assets/TilesetFloor.png", sf::IntRect(0, 336, 160, 48));//fundo neve

    criarJogadores(numJog);
    criarChao(sf::IntRect(16, 192, 16, 48));//chão neve
    criarCenario();
    criarInimigos();
}

Fase_Gelo::~Fase_Gelo()
{

}

void Fase_Gelo::criarInimigos()
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

void Fase_Gelo::criarInimChefes(const sf::Vector2f posicoes[])
{
    Samurai* pC = new Samurai(posicoes[0].x, posicoes[0].y, &lista_ents, &GC);//só um chefão por fase
    lista_ents.incluir(pC);
    GC.incluirInimigo(pC);
}

void Fase_Gelo::criarObstaculos()
{
    criarObstaculosDificeis();
}

void Fase_Gelo::criarObstaculosDificeis()
{
    const sf::Vector2f posicoes[NUM_OBST_DANOSOS] =
    {
        sf::Vector2f(150, 522),
        sf::Vector2f(350, 522),
        sf::Vector2f(550, 522),
        sf::Vector2f(700, 522)
    };
    
    for (int i = 0; i < NUM_OBST_DANOSOS; i++)
    {
        Obst_Dificil* pO = new Obst_Dificil(posicoes[i].x, posicoes[i].y, 30, 30, 2);
        lista_ents.incluir(pO);
        GC.incluirObstaculo(pO);
    }
}