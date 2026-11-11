#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fase_Rosa.hpp"
#include "Fase_Gelo.hpp"

Jogo::Jogo() : GG(), menu(), pFase(nullptr)
{
    Ente::setGG(&GG);//entes são conectados com gerenciador
    srand(time(nullptr));
}

Jogo::~Jogo()
{
    delete pFase;
    pFase = nullptr;
}

void Jogo::executar()
{
    while (GG.estaAberta())//loop do jogo
    {
        GG.processarEventos();
        GG.limpar();

        if (pFase == nullptr)//ainda no menu
        {
            menu.executar();

            if (menu.getFase() == 1)//fase 1
                pFase = new Fase_one();

            if (menu.getFase() == 2)//fase 2
                pFase = new Fase_two();
        }

        else
            pFase->executar();
        
        GG.mostrar();
    }
}