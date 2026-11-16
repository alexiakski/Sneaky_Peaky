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

        if (pFase != nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//ESC pausa
            menu.pausar();
            
        if (pFase == nullptr || menu.getPausado())// no menu ou na pausa
        {
            menu.executar();

            if (pFase == nullptr)//no menu: espera escolher a fase
            {
                if (menu.getFase() == 1)//fase 1
                    pFase = new Fase_one(menu.getNumJog());

                if (menu.getFase() == 2)//fase 2
                    pFase = new Fase_two(menu.getNumJog());
            }

            else if (menu.getFase() == 0)//escolheu voltar para o menu
            {
                delete pFase;
                pFase = nullptr;
            }
        }

        else
        {
            pFase->executar();

            if (pFase->getFimDeJogo())
            {
                menu.fimDeJogo(pFase->getPontos());
                delete pFase;
                pFase = nullptr;
            }
        }
        
        GG.mostrar();
    }
}