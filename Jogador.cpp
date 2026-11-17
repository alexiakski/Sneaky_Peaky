#include "stdafx.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"

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

void Jogador::colidir(Inimigo* pIn)
{
    if (pIn == nullptr)
        return;

    sf::FloatRect boundsJogador = getBounds();  
    sf::FloatRect boundsInimigo = pIn->getBounds();

    float pesJogador = boundsJogador.top + boundsJogador.height;
    float cabecaInimigo = boundsInimigo.top;
   
    if (pesJogador - velocidadeY <= cabecaInimigo + 5 && velocidadeY > 0)
    {
        *pIn -= 1;
        ++(*this);
        velocidadeY = -10; 
    }
    else
    {
        *this -= 1;
    }
}
void Jogador::sofrerAtaque(int dano)
{
    *this -= dano;
}

void Jogador::salvar()
{
    // Implementar no requisito 10
}

void Jogador::mover()
{
    float velocidade = 2;
    bool andando = false;
    
    //verifica o movimento do jogador
    if (sf::Keyboard::isKeyPressed(teclaCima) && chao)// não pula se já estiver no ar
    {
        /*y -= velocidade;
        direcao = 1;
        andando = true;*/

        velocidadeY = -10;
        chao = false;
    }
    if (sf::Keyboard::isKeyPressed(teclaBaixo))//não funciona mais
    {
        /*y += velocidade;
        direcao = 0;
        andando = true;*/
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

    if (x < 0)//chão
        x = 0;
    if (x > 800 - largura)//fica dentro da tela
        x = 800 - largura;

    aplicarGravidade();

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

    if (pFig != nullptr) {
      pFig->setTextureRect(sf::IntRect(direcao * 16, quadro * 16, 16, 16));//coloca o recorte correto da sprite
      pFig->setPosition(x, y);
    }
}

void Jogador::executar()
{
   mover();
}

Jogador& Jogador::operator++()
{
    pontos++;
    return *this;
}

int Jogador::getPontos() const
{
    return pontos;
}

void Jogador::reposicionarJogObst(const sf::FloatRect& rectObstaculo)
{
    sf::FloatRect jog(x, y, largura, altura);

    if (!jog.intersects(rectObstaculo))
        return;

    float centroJogX = x + largura / 2.0f;
    float centroJogY = y + altura / 2.0f;

    float centroObsX = rectObstaculo.left + rectObstaculo.width / 2.0f;
    float centroObsY = rectObstaculo.top + rectObstaculo.height / 2.0f;

    if (abs(centroJogX - centroObsX) >
        abs(centroJogY - centroObsY))
    {
        // lados
        if (centroJogX < centroObsX)
            x = rectObstaculo.left - largura;
        else
            x = rectObstaculo.left + rectObstaculo.width;
    }
    else
    {
        // cima baixo
        if (centroJogY < centroObsY)
            y = rectObstaculo.top - altura;

            velocidadeY = 0;
            chao = true;
        else
            y = rectObstaculo.top + rectObstaculo.height;
    }
}

void Jogador::reposicionarJogInim(const sf::FloatRect& rectInimigo)
{
    sf::FloatRect jog(x, y, largura, altura);

    if (!jog.intersects(rectInimigo))
        return;

    float centroJogX = x + largura / 2.0f;
    float centroJogY = y + altura / 2.0f;

    float centroInimX = rectInimigo.left + rectInimigo.width / 2.0f;
    float centroInimY = rectInimigo.top + rectInimigo.height / 2.0f;

    if (abs(centroJogX - centroInimX) >
        abs(centroJogY - centroInimY))
    {
        //lados
        if (centroJogX < centroInimX)
            x = rectInimigo.left - largura;
        else
            x = rectInimigo.left + rectInimigo.width;
    }
    else
    {
        //cima baixo
        if (centroJogY < centroInimY)
            y = rectInimigo.top - altura;
        else
            y = rectInimigo.top + rectInimigo.height;
    }
}