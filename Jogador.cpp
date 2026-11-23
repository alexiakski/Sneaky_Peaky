#include "stdafx.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Gerenciador_Grafico.hpp"
namespace Entidades::Personagens 
{

Jogador::Jogador(float x, float y, int largura, int altura, int num_jog)
        : Personagem(x, y, largura, altura, MAX_VIDAS), coracao(sf::Vector2f(32, 32)), cX(num_jog == 1 ? 10 : 800 - 10 - 32)
{
    pontos = 0;
    direcao = 0;
    quadro = 0;
    contador = 0;
    empurraoX = 0;

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
    
    if (pGG != nullptr)
    {
        sf::Texture* pTex = pGG->carregarTextura("assets/Heart.png");
        if (pTex != nullptr)
            coracao.setTexture(pTex);
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
    sf::FloatRect sobreposicao;

    boundsJogador.intersects(boundsInimigo, sobreposicao);

    if (sobreposicao.width < sobreposicao.height)//encostou pelos lados: leva dano
    {
        pIn->danificar(this);//chama o danificar() do inimigo
        reposicionarJogInim(boundsInimigo);
    }
    else if (boundsJogador.top < boundsInimigo.top)//veio de cima: pisou no inimigo
    {
        *pIn -= 1;
        if (!pIn->getAtivo())
                *this += pIn->getNivelMaldade() * 10;
        velocidadeY = -6;
    }
    else//veio de baixo: bate a cabeça e cai, sem dano
    {
        y = boundsInimigo.top + boundsInimigo.height;
        velocidadeY = 0;
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

void Jogador::desenhar()
{
    Ente::desenhar();

    if (pGG == nullptr)
        return;

    int quadro = num_vidas * 4 / MAX_VIDAS;//4 = cheio (vermelho), 0 = vazio (preto)

    coracao.setTextureRect(sf::IntRect(quadro * 16, 0, 16, 16));
    coracao.setPosition(cX, 10);
    pGG->desenhar(coracao);
    
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

    x += empurraoX;//obstaculo medio
    empurraoX *= 0.9f;

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
   atualizarInvincibilidade();
    mover();
}

/*Jogador& Jogador::operator++()
{
    pontos++;
    return *this;
}*/

Jogador& Jogador::operator+=(int pontos)
{
    this->pontos += pontos;
    return *this;
}

int Jogador::getPontos() const
{
    int total = pontos - (MAX_VIDAS - num_vidas);//1 ponto a menos por vida perdida
    return total > 0 ? total : 0;//não fica negativo
}

void Jogador::reposicionarJogObst(const sf::FloatRect& rectObstaculo)
{
    sf::FloatRect jog(x, y, largura, altura);

    if (!jog.intersects(rectObstaculo))
        return;

    else{
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
            {
                y = rectObstaculo.top - altura;

                velocidadeY = 0;
                chao = true;
            }
            else
                y = rectObstaculo.top + rectObstaculo.height;
        }
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

void Jogador::setEmpurraoX(float empurraoX)
{
    this->empurraoX = empurraoX;
}

}