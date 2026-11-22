#include "stdafx.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Inim_Bambu.hpp"
#include "Chao.hpp"
#include "Plataforma.hpp"

using namespace Entidades;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases
{
static const sf::FloatRect plataformas[MAX_PLATAFORMAS] =
{
    //linha y=470 (colunas 0, 2, 4)
    sf::FloatRect( 72, 470, 106, 40),
    sf::FloatRect(354, 470, 106, 40),
    sf::FloatRect(636, 470, 106, 40),

    //linha y=410 (colunas 1, 3)
    sf::FloatRect(210, 410, 106, 40),
    sf::FloatRect(498, 410, 106, 40),

    //linha y=350 (colunas 0, 2, 4)
    sf::FloatRect( 72, 350, 106, 40),
    sf::FloatRect(354, 350, 106, 40),
    sf::FloatRect(636, 350, 106, 40),

    //linha y=290 (colunas 1, 3)
    sf::FloatRect(210, 290, 106, 40),
    sf::FloatRect(498, 290, 106, 40),

    //linha y=230 (colunas 0, 2, 4)
    sf::FloatRect( 72, 230, 106, 40),
    sf::FloatRect(354, 230, 106, 40),
    sf::FloatRect(636, 230, 106, 40),

    //linha y=170 (colunas 1, 3)
    sf::FloatRect(210, 170, 106, 40),
    sf::FloatRect(498, 170, 106, 40)
};

static const float vagasChao[VAGAS_CHAO] = { 40, 130, 220, 310, 400, 490, 580 };

Fase::Fase() : Ente(), lista_ents(), GC(), pJog1(nullptr), pJog2(nullptr)
{
    pFig->setSize(sf::Vector2f(800, 600));//tamanho do fundo = tamanho da janela

    for (int i = 0; i < MAX_PLATAFORMAS; i++)
        plataformaOcupada[i] = false;

    for (int i = 0; i < VAGAS_CHAO; i++)
        chaoOcupado[i] = false;
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
    criarInimigos();
    criarObstaculos();//virtual pq chama o da Fase_one ou da Fase_two
}

void Fase::criarInimFaceis()
{
    int quantidade = sortearQuant(MIN_INIMIGOS, MAX_INIMIGOS);

    for (int i = 0; i < quantidade; i++)
    {
        Inim_Bambu* pI = new Inim_Bambu(0,0);
        posicionarEmPlataforma(pI);
        lista_ents.incluir(pI);
        GC.incluirInimigo(pI);
    }
}

void Fase::criarPlataformas()
{
    int quantidade = sortearQuant(MIN_PLATAFORMAS, MAX_PLATAFORMAS);

    for (int i = 0; i < MAX_PLATAFORMAS; i++)
    {
        if (i >= quantidade)
        {
            plataformaOcupada[i] = true;//se a plataforma não existe ninguém é posicionado nela
            continue;
        }

        Plataforma* pP = new Plataforma(plataformas[i].left, plataformas[i].top, plataformas[i].width, plataformas[i].height);
        lista_ents.incluir(pP);
        GC.incluirObstaculo(pP);
    }
}

int Fase::sortearQuant(int min, int max) const
{
    return min + rand() % (max - min + 1);
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

void Fase::posicionarEmPlataforma(Entidade* pE)
{
    if (pE == nullptr)
        return;

    int livres[MAX_PLATAFORMAS];
    int numLivres = 0;

    for (int i = 0; i < MAX_PLATAFORMAS; i++)//junta os índices das plataformas livres
        if (!plataformaOcupada[i])
            livres[numLivres++] = i;

    if (numLivres == 0)//todas vagas ocupadas: vai para o chão
    {
        posicionarNoChao(pE);
        return;
    }

    int sorteada = livres[rand() % numLivres];
    plataformaOcupada[sorteada] = true;//um inimigo por plataforma

    const sf::FloatRect& p = plataformas[sorteada];
    pE->setPosicao(p.left + (p.width - pE->getLargura()) / 2,p.top - pE->getAltura());
}

void Fase::posicionarNoChao(Entidade* pE)
{
    if (pE == nullptr)
        return;

    int livres[VAGAS_CHAO];
    int numLivres = 0;

    for (int i = 0; i < VAGAS_CHAO; i++)//junta os índices das vagas livres
        if (!chaoOcupado[i])
            livres[numLivres++] = i;

    if (numLivres == 0)//sem vaga: x aleatório (último recurso)
    {
        pE->setPosicao(rand() % (int)(600 - pE->getLargura()), 552 - pE->getAltura());
        return;
    }

    int sorteada = livres[rand() % numLivres];
    chaoOcupado[sorteada] = true;

    pE->setPosicao(vagasChao[sorteada], 552 - pE->getAltura());
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
}