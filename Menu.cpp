#include "stdafx.hpp"
#include "Menu.hpp"
#include "Gerenciador_Grafico.hpp"

Menu::Menu() : Ente (), tela(0), numJog(1), numFase(0), teclaPressionada(false)//1 jogador como padrão
{
    
}

Menu::~Menu()
{

}

int Menu::getFase() const
{
    return numFase;
}

void Menu::executar()
{
    escolher();

    pFig->setSize(sf::Vector2f(576, 576));//4x(114x144)
    pFig->setPosition(112, 12);//(800-576)/2 e (600-576)/2: centralizado na janela
    setTextura ("assets/Menu.png", sf::IntRect(496, 176, 144, 144));//rectLeft, rectTop, rectWidth, rectHeight

    desenhar();//fundo

    switch (tela)//todos os texto ficam dentro da parte branca (108-492)
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
        escrever("4-VOLTAR", 400);
        break;
    case 3:
        escrever("RANKING", 140);
        escrever("EM BREVE", 280);//leitura do arquivo
        escrever("4-VOLTAR", 400);
        break;

    default:
        break;
    }
}

void Menu::escolher()
{
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
    else if (tecla == 4)//voltar
        tela = 0;

    else if (tela == 1 && tecla <= 2)
    {
        numJog = tecla;
        tela = 0;
    }

    else if (tela == 2 && tecla <= 2)
        numFase = tecla;//o Jogo cria a fase quando getFase() != 0
}

void Menu::escrever(string texto, float y)
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