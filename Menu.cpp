#include "stdafx.hpp"
#include "Menu.hpp"
#include "Gerenciador_Grafico.hpp"

Menu::Menu() : Ente (), tela(0), numJog(1), numFase(0), pontos(0), faseVencida(0), telaFinal(0), teclaPressionada(false), nome("")//1 jogador como padrão
{
    ifstream arq("ranking.txt");
    string nome;
    int pts;

    while (arq >> nome >> pts)
        ranking.insert({pts, nome});

}

Menu::~Menu()
{
    ofstream arq("ranking.txt");
    for (auto& r : ranking)
        arq << r.second << ' ' << r.first << '\n';
}

int Menu::getFase() const
{
    return numFase;
}

int Menu::getNumJog() const
{
    return numJog;
}

bool Menu::getPausado() const
{
    return tela == 4;
}

void Menu::pausar()
{
    tela = 4;
}

void Menu::executar()
{
    escolher();

    pFig->setSize(sf::Vector2f(576, 576));//4x(114x144)
    pFig->setPosition(112, 12);//(800-576)/2 e (600-576)/2: centralizado na janela
    setTextura ("assets/Menu.png", sf::IntRect(176, 176, 144, 144));//rectLeft, rectTop, rectWidth, rectHeight

    desenhar();//fundo

    switch (tela)//todos os texto ficam dentro da parte mais escura (108-492)
    {
    case 0:
        escrever("SNEAKY PEAKY", 140);
        escrever("1-JOGADORES: " + to_string(numJog), 220);
        escrever("2-FASES", 280);
        escrever("3-RANKING", 340);
        escrever("4-SAIR", 400);
        break;
    case 1:
        escrever("JOGADORES", 140);
        escrever("1-1 JOGADOR", 220);
        escrever("2-2 JOGADORES", 280);
        escrever("4-VOLTAR", 400);
        break;
    case 2:
        escrever("FASES", 140);
        escrever("1-FASE 1", 220);
        escrever("2-FASE 2", 280);
        escrever("3-CARREGAR JOGO", 340);
        escrever("4-VOLTAR", 400);
        break;
    case 3:
    {
        escrever("RANKING", 140);
        int i = 0;
        for (auto it = ranking.begin(); it != ranking.end() && i < 5; it++, i++)
            escrever(to_string(i + 1) + "-" + it->second + " " + to_string(it->first), 200 + i * 36);
        escrever("4-VOLTAR", 400);
        break;
    }
    case 4:
        escrever("PAUSADO", 140);
        escrever("1-CONTINUAR", 220);
        escrever("4-VOLTAR PARA O MENU", 400);
        break;
    case 5:
        escrever("GAME OVER", 140);
        escrever("PONTOS: " + to_string(pontos), 220);
        escrever("4-VOLTAR PARA O MENU", 280);
        break;
    case 6:
        escrever("PARABENS!", 140);
        escrever("VOCE VENCEU!", 180);
        escrever("PONTOS: " + to_string(pontos), 240);
        if (faseVencida == 1)
            escrever("1-PROXIMA FASE", 300);
        escrever("4-VOLTAR PARA O MENU", 340);
        break;
    case 7:
    escrever("SEU NOME:", 140);
    escrever(nome + "_", 220);
    escrever("ENTER-CONFIRMAR", 400);
    break;

    default:
        break;
    }
}

void Menu::escolher()
{
    if (tela == 7)//digitando o nome
    {
        int k = sf::Keyboard::A;
        while (k <= sf::Keyboard::Z && !sf::Keyboard::isKeyPressed((sf::Keyboard::Key)k))
            k++;//para na letra apertada (ou passa do Z se nenhuma)
        bool enter = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);

        if (!teclaPressionada && enter && !nome.empty())
        {
            ranking.insert({pontos, nome});
            tela = telaFinal;
        }
        else if (!teclaPressionada && k <= sf::Keyboard::Z && nome.size() < 8)
            nome += 'A' + k;

        teclaPressionada = (k <= sf::Keyboard::Z || enter);//uma letra por aperto
        return;
    }

    int tecla = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        tecla = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        tecla = 2;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        tecla = 3;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        tecla = 4;

    if (tecla == 0 || teclaPressionada)//nada apertado ou ainda segurando a mesma tecla
    {
        teclaPressionada = (tecla != 0);//quando a tecla é solta
        return;
    }
    teclaPressionada = true;

    if (tela == 0)//principal
    {
        if (tecla == 4)
            pGG->fechar();
        else
            tela = tecla;//1 jogadores, 2 fases, 3 ranking
    }
    
    else if (tela == 4)//pausa
    {
        if (tecla == 1)//continuar 
            tela = 0;
        else if (tecla == 4)//voltar para o menu
        {
            numFase = 0;                               
            tela = 0;
        }
    }

    else if(tela == 6 && tecla == 1 && faseVencida == 1)
    {
        numFase = 2;
        tela = 0;
    }

    else if (tecla == 4)//voltar
        tela = 0;

    else if (tela == 1 && tecla <= 2)
    {
        numJog = tecla;
        tela = 0;
    }

    else if (tela == 2 && tecla <= 3)
        numFase = tecla;//o Jogo cria a fase quando getFase() != 0
}

void Menu::escrever(const string texto, float y)
{
    float x = 400 - (int)texto.size() * 12;//centraliza: 400 é o meio da janela, 12 é meia letra
    pFig->setSize(sf::Vector2f(24, 30));//tamanho de cada letra

    for (int i = 0; i < (int)texto.size(); i++)
    {
        int n = texto[i] - 32;//a imagem começa no espaço (código 32)
        setTextura("assets/font24x30.png", sf::IntRect((n % 15) * 24, (n / 15) * 30, 24, 30));//15 letras por linha: coluna n % 15, linha n / 15
        pFig->setPosition(x + i * 24, y);//cada letra 24 px à direita da anterior
        desenhar();
    }
}

void Menu::fimDeJogo(int pontos, bool venceu)
{
    this->pontos = pontos;

    if (venceu)
    {
        faseVencida = numFase;
        telaFinal = 6;
    }
    else
        telaFinal = 5;

    tela = 7;
    numFase = 0;
}
