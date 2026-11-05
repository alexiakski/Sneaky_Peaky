#include "stdafx.hpp"
#include "Jogador.hpp"

Jogador::Jogador(float x, float y, int largura, int altura, int num_jog) : Personagem(x, y, largura, altura, 3)//3?
{
    pontos = 0;
    direcao = 0;    //começa olhando para baixo
    quadro = 0;     //começa parado
    contador = 0;

    if (num_jog == 1)
    {
        teclaCima = sf::Keyboard::Up;
        teclaBaixo = sf::Keyboard::Down;
        teclaEsquerda = sf::Keyboard::Left;
        teclaDireita = sf::Keyboard::Right;
    }

    else
    {
        teclaCima = sf::Keyboard::W;
        teclaBaixo = sf::Keyboard::S;
        teclaEsquerda = sf::Keyboard::A;
        teclaDireita = sf::Keyboard::D;
    }
}

Jogador::~Jogador()
{

}

void Jogador::salvar()
{
    // Implementar no requisito 10
}

void Jogador::mover()
{
    float velocidade = 2;
    bool andando = false;

    if (sf::Keyboard::isKeyPressed(teclaCima))//verifica o movimento do jogador
    {
        y -= velocidade;
        direcao = 1;
        andando = true;
    }
    if (sf::Keyboard::isKeyPressed(teclaBaixo))
    {
        y += velocidade;
        direcao = 0;
        andando = true;
    }
    if (sf::Keyboard::isKeyPressed(teclaEsquerda))
    {
        x -= velocidade;
        direcao = 2;
        andando = true;
    }
    if (sf::Keyboard::isKeyPressed(teclaDireita))
    {
        x += velocidade;
        direcao = 3;
        andando = true;
    }

    if (andando)//escolhe o frame da animação
    {
        contador++;
        if (contador >= 9)
        {
            quadro = (quadro + 1) % 4;
            contador = 0;
        }
    }
    else
    {
        quadro = 0;
        contador = 0;
    }

    pFig->setTextureRect(sf::IntRect(direcao * 16, quadro * 16, 16, 16));//coloca o recorte correto da sprite
    pFig->setPosition(x, y);
}

void Jogador::executar()
{
   mover();
}