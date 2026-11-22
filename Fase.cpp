#include "stdafx.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Inim_Bambu.hpp"
#include "Chao.hpp"
#include "Plataforma.hpp"

#define NUM_PLATAFORMAS 15

Fase::Fase() : Ente(), lista_ents(), GC(), pJog1(nullptr), pJog2(nullptr)
{
    pFig->setSize(sf::Vector2f(800, 600));//tamanho do fundo = tamanho da janela
}

Fase::~Fase()
{
    pJog1 = nullptr;
    pJog2 = nullptr;
}

void Fase::executar()
{
    desenhar();//fundo
    lista_ents.percorrer();//cmovimento de cada entidade
    GC.executar();
    lista_ents.desenhar();//desenho de cada entidade
}

void Fase::criarJogadores(int numJog)
{
    pJog1 = new Jogador(750, 520, 24, 32, 1);
    pJog1->setTextura("assets/NinjaRedWalk.png", sf::IntRect(0, 0, 16, 16));//textura do primeiro jogador - recorte da imagem (0,0) até (16,16)
    lista_ents.incluir(pJog1);
    GC.incluirJogador(pJog1);

    if (numJog == 2)
    {
        pJog2 = new Jogador(710, 520, 24, 32, 2);
        pJog2->setTextura("assets/NinjaEskimoWalk.png", sf::IntRect(0, 0, 16, 16));//textura do primeiro jogador - recorte da imagem (0,0) até (16,16)
        lista_ents.incluir(pJog2);
        GC.incluirJogador(pJog2);
    }
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
        Inim_Bambu* pI = new Inim_Bambu(posicoes[i].x, posicoes[i].y);
        lista_ents.incluir(pI);
        GC.incluirInimigo(pI);
    }
}

void Fase::criarPlataformas()
{
    const sf::FloatRect plataformas[NUM_PLATAFORMAS] =
    {
        //linha y=470 (colunas 0, 2, 4)
        sf::FloatRect( 72, 470, 92, 46),
        sf::FloatRect(354, 470, 92, 46),
        sf::FloatRect(636, 470, 92, 46),

        //linha y=410 (colunas 1, 3)
        sf::FloatRect(210, 410, 92, 46),
        sf::FloatRect(498, 410, 92, 46),

        //linha y=350 (colunas 0, 2, 4)
        sf::FloatRect( 72, 350, 92, 46),
        sf::FloatRect(354, 350, 92, 46),
        sf::FloatRect(636, 350, 92, 46),

        //linha y=290 (colunas 1, 3)
        sf::FloatRect(210, 290, 92, 46),
        sf::FloatRect(498, 290, 92, 46),

        //linha y=230 (colunas 0, 2, 4)
        //sf::FloatRect( 72, 230, 92, 46),
        sf::FloatRect(354, 230, 92, 46),
        //sf::FloatRect(636, 230, 92, 46),

        /*//linha y=170 (colunas 1, 3)
        sf::FloatRect(210, 170, 92, 46),
        sf::FloatRect(498, 170, 92, 46)*/
    };

    for (int i = 0; i < NUM_PLATAFORMAS; i++)
    {
        Plataforma* pP = new Plataforma(plataformas[i].left, plataformas[i].top, plataformas[i].width, plataformas[i].height);
        lista_ents.incluir(pP);
        GC.incluirObstaculo(pP);
    }
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

void Fase::criarChao(sf::IntRect recorte)
{
    Chao* pChao = new Chao(0, 552, 800, 48, recorte);//faixa de 48px
    lista_ents.incluir(pChao);
    GC.incluirChao(pChao);
}

bool Fase::getFimDeJogo() const
{
    bool vivo1 = (pJog1 != nullptr && pJog1->getAtivo());
    bool vivo2 = (pJog2 != nullptr && pJog2->getAtivo());

    return !vivo1 && !vivo2;//jogo termina quando todos os jogadores morrem
}

bool Fase::getVitoria() const
{
    return GC.todosInimigosMortos();// fase é vencida quando todos os inimigos são mortos
}

int Fase::getPontos() const
{
    int pontos = 0;

    if(pJog1 != nullptr)
        pontos += pJog1->getPontos();
    if(pJog2 != nullptr)
        pontos += pJog2->getPontos();
    
    return pontos;
}