#include "stdafx.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Inim_Bambu.hpp"
#include "Chao.hpp"
#include "Plataforma.hpp"
#include "Inim_DuendeAzul.hpp"
#include "Samurai.hpp"
#include "Obst_Slime.hpp"
#include "Obst_Espinhos.hpp"
#include "Projetil.hpp"

using namespace Entidades;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases
{
static const sf::FloatRect plataformas[MAX_PLATAFORMAS] =
{
    //linha y=470 (colunas 0, 2, 4)
    sf::FloatRect( 60, 470, 116, 46),
    sf::FloatRect(342, 470, 116, 46),
    sf::FloatRect(624, 470, 116, 46),

    //linha y=410 (colunas 1, 3)
    sf::FloatRect(198, 410, 116, 46),
    sf::FloatRect(486, 410, 116, 46),

    //linha y=350 (colunas 0, 2, 4)
    sf::FloatRect( 60, 350, 116, 46),
    sf::FloatRect(342, 350, 116, 46),
    sf::FloatRect(624, 350, 116, 46),

    //linha y=290 (colunas 1, 3)
    sf::FloatRect(198, 290, 116, 46),
    sf::FloatRect(486, 290, 116, 46),

    //linha y=230 (colunas 0, 2, 4)
    sf::FloatRect( 60, 230, 116, 46),
    sf::FloatRect(342, 230, 116, 46),
    sf::FloatRect(624, 230, 116, 46),

    //linha y=170 (colunas 1, 3)
    sf::FloatRect(198, 170, 116, 46),
    sf::FloatRect(486, 170, 116, 46)
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

void Fase::salvar()
{
    const string arquivos[] = {"jogador", "inim_bambu", "inim_duendeazul", "samurai", "projetil",
                               "plataforma", "obst_slime", "obst_espinhos", "chao"};

    for (const string& a : arquivos)
        ofstream("save/" + a + ".txt");//abre sem ios::app: apaga o salvamento anterior

    lista_ents.salvar();
}

void Fase::recuperar()
{
    float x, y, velY, valor;
    bool ativo, danoso;
    int vidas, invenc, nivel, num, pts;
    string linha;

    //jogadores: cria 1 ou 2 como no jogo normal e depois aplica o estado salvo
    vector<string> linhas;
    ifstream arqJ("save/jogador.txt");
    while (getline(arqJ, linha))
        linhas.push_back(linha);

    criarJogadores(linhas.size());

    for (const string& l : linhas)
    {
        istringstream in(l);
        in >> x >> y >> ativo >> vidas >> velY >> invenc >> num >> pts;

        Jogador* pJ = (num == 1) ? pJog1 : pJog2;
        pJ->setPosicao(x, y);
        pJ->setAtivo(ativo);
        pJ->setNumVidas(vidas);
        pJ->setVelocidadeY(velY);
        *pJ += pts;
    }

    //inimigos: os três arquivos começam com os mesmos 7 campos
    const string inimigos[] = {"inim_bambu", "inim_duendeazul", "samurai"};

    for (int t = 0; t < 3; t++)
    {
        ifstream arq("save/" + inimigos[t] + ".txt");

        while (arq >> x >> y >> ativo >> vidas >> velY >> invenc >> nivel)
        {
            getline(arq, linha);//resto da linha (contador, direcao, recarga): recomeçam do zero

            Inimigo* pI;
            if (t == 0)
                pI = new Inim_Bambu(x, y);
            else if (t == 1)
                pI = new Inim_DuendeAzul(x, y);
            else
                pI = new Samurai(x, y, &lista_ents, &GC);

            pI->setAtivo(ativo);
            pI->setNumVidas(vidas);
            pI->setVelocidadeY(velY);
            lista_ents.incluir(pI);
            GC.incluirInimigo(pI);
        }
    }

    //obstáculos: x y ativo danoso + o atributo próprio de cada um
    const string obstaculos[] = {"plataforma", "obst_slime", "obst_espinhos"};

    for (int t = 0; t < 3; t++)
    {
        ifstream arq("save/" + obstaculos[t] + ".txt");

        while (arq >> x >> y >> ativo >> danoso >> valor)
        {
            Obstaculo* pO;
            if (t == 0)
                pO = new Plataforma(x, y, 116, 46, valor);//valor = velocidadeY
            else if (t == 1)
                pO = new Obst_Slime(x, y, 30, 30, valor);//valor = forca
            else
                pO = new Obst_Espinhos(x, y, 30, 30, valor);//valor = danosidade

            lista_ents.incluir(pO);
            GC.incluirObstaculo(pO);
        }
    }

    //projéteis: x y ativo dano velocidade
    ifstream arqP("save/projetil.txt");
    while (arqP >> x >> y >> ativo >> num >> valor)
    {
        Projetil* pP = new Projetil(x, y, 20, 20, num, valor);//num = dano, valor = velocidade
        lista_ents.incluir(pP);
        GC.incluirProjetil(pP);
    }
}

}