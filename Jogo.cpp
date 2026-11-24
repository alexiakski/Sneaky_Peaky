#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fase_Rosa.hpp"
#include "Fase_Gelo.hpp"

using namespace Fases;

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
        {
            menu.pausar();
            pFase->salvar();
            ofstream("save/jogo.txt") << (dynamic_cast<Fase_Gelo*>(pFase) ? 2 : 1);
        }
            
        if (pFase == nullptr || menu.getPausado())// no menu ou na pausa
        {
            menu.executar();

            if (pFase == nullptr)//no menu: espera escolher a fase
            {
                if (menu.getFase() == 1)//fase 1
                    pFase = new Fase_Rosa(menu.getNumJog());

                if (menu.getFase() == 2)//fase 2
                    pFase = new Fase_Gelo(menu.getNumJog());
                
                if (menu.getFase() == 3)//carregar jogo salvo
                {
                    int fase = 0;
                    ifstream("save/jogo.txt") >> fase;

                    if (fase == 1)
                        pFase = new Fase_Rosa(0, true);
                    else if (fase == 2)
                        pFase = new Fase_Gelo(0, true);
                }
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

            if (pFase->getFimDeJogo() || pFase->getVitoria())
            {
                menu.fimDeJogo(pFase->getPontos(), pFase->getVitoria());
                delete pFase;
                pFase = nullptr;
            }
        }
        
        GG.mostrar();
    }
}