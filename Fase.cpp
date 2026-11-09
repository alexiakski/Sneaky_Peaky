#include "stdafx.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Inim_Facil.hpp"

#define NUM_PLATAFORMAS 3

Fase::Fase() : Ente(), lista_ents(), GC(), pJog1(nullptr)
{
    pFig->setSize(sf::Vector2f(800, 600));//tamanho do fundo = tamanho da janela
}

Fase::~Fase()
{
    pJog1 = nullptr;
}

void Fase::executar()
{
    desenhar();//fundo
    lista_ents.percorrer();//cmovimento de cada entidade
    //GC.executar();            //descomentar quando a Talita implementar
    lista_ents.desenhar();//desenho de cada entidade
}

void Fase::criarJogadores()
{
    pJog1 = new Jogador(750, 500, 24, 32, 1);
    pJog1->setTextura("assets/NinjaRedWalk.png", sf::IntRect(0, 0, 16, 16));//textura do primeiro jogador - recorte da imagem (0,0) até (16,16)
    lista_ents.incluir(pJog1);
    //GC.incluirJogador(pJog1);   //quando existir
}

void Fase::criarCenario()
{
    criarPlataformas();
    criarObstaculos();//virtual pq chama o da Fase_one ou da Fase_two
}

void Fase::criarInimFaceis(const sf::Vector2f posicoes[], int total)
{
    int quantidade = 3 + rand() % (total - 3 + 1);

    for (int i = 0; i < quantidade; i++)
    {
        Inim_Facil* pI = new Inim_Facil(posicoes[i].x, posicoes[i].y);
        lista_ents.incluir(pI);
        //GC.incluirInimigo(pI);
    }
}

void Fase::criarPlataformas()
{
    //quando a Plataforma existir (Talita, T3):
    //Plataforma* pChao = new Plataforma(0, 550, 800, 50);
    //lista_ents.incluir(pChao);
    //GC.incluirObstaculo(pChao);
}

void Fase::setFundo(const std::string& caminho, sf::IntRect ladrilho)
{
    if (pGG == nullptr)
        return;

    sf::Texture* pTex = pGG->carregarTextura(caminho, ladrilho); //pedaço de 16x16

    if (pTex == nullptr)
        return;

    pTex->setRepeated(true); //repete como azulejo
    pFig->setTexture(pTex);
    pFig->setTextureRect(sf::IntRect(0, 0, 267, 200)); //área maior que a textura = repete
}