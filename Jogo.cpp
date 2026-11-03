#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"

Jogo::Jogo() : GG(), jog1(100, 100, 48, 48, 1)//posicao (100,100) e tamanho (48,48) e jogador (1)
{
    Ente::setGG(&GG);//entes são conectados com gerenciador
    jog1.setTextura("assets/NinjaRedWalk.png", sf::IntRect(0, 0, 16, 16));//textura do primeiro jogador - recorte da imagem (0,0) até (16,16)
}

Jogo::~Jogo()
{

}

void Jogo::executar()
{
    while (GG.estaAberta())//loop do jogo
    {
        GG.processarEventos();
        jog1.executar();
        GG.limpar();
        jog1.desenhar();
        GG.mostrar();
    }
}