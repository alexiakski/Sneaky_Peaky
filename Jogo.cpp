#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"

Jogo::Jogo() : GG(), jog1(100, 100, 50, 50)//posicao (100,100) e tamanho (50,50)
{
    Ente::setGG(&GG);//entes são conectados com gerenciador
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