#include "Gerenciador_Colisoes.hpp"
#include "Ente.hpp"

using namespace Entidades;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Gerenciadores
{
Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), LPs(), LCs(), pJog1(nullptr), pJog2(nullptr)
{

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();
    pJog1 = nullptr;
    pJog2 = nullptr;
}

bool Gerenciador_Colisoes::verificarColisao (Entidade *pE1, Entidade *pE2)
{
    if(pE1 == NULL || pE2 == NULL)
        return false;
    
    if(!pE1->getAtivo() || !pE2->getAtivo())//verifica se estão vivos
        return false;

    return (pE1->getBounds()).intersects(pE2->getBounds());
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs ()//alterei para incluir Jog2
{
    Jogador* jogs[2] = {pJog1, pJog2};

    for (Jogador* pJ : jogs){

        if (pJ == nullptr) continue;

        for (Obstaculo *pO : LOs)
        {
            if (pO != nullptr && verificarColisao(pJ, pO))
            {
                pO->obstaculizar(pJ);
            }
        }
    }
}
void Gerenciador_Colisoes::tratarColisoesJogsInimgs ()//alterei para incluir Jog2
{
    Jogador* jogs[2] = {pJog1, pJog2};

    for (Jogador* pJ : jogs)
    {
        if (pJ == nullptr) continue;

        for (size_t i = 0; i < LIs.size(); i++)
        {
            Inimigo *pI = LIs[i];
            if (pI != nullptr && verificarColisao(pJ, pI))
                pJ->colidir(pI);
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesInimgsObstacs ()
{
    for (Inimigo *pI : LIs)
    {
        if (pI == nullptr) continue;

        for (Obstaculo *pO : LOs)
        {
            if (pO != nullptr && verificarColisao(pI, pO))
                pI->reposicionar(pO->getBounds());
        }
    }
}

bool Gerenciador_Colisoes::todosInimigosMortos() const
{
    for (size_t i = 0; i < LIs.size(); i++)
        if(LIs[i] != nullptr && LIs[i]->getAtivo())//percorre todos os inimigos e verifica se eles estão vivos
            return false;
    return true;// se todos estiverem mortos
}

void Gerenciador_Colisoes::tratarColisoesJogsProjeteis ()//alterei para incluir Jog2
{
    Jogador* jogs[2] = {pJog1, pJog2};

    for (Jogador* pJ : jogs)
    {
        if (pJ == nullptr) continue;

        for (Projetil *pP : LPs)
        {
            if (pP != nullptr && pP->getAtivo() && verificarColisao(pJ, pP))
                pP->colidir(pJ);
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesChao()
{
    for (Chao *pC : LCs)
    {
        if (pC == nullptr)
            continue;

        if (pJog1 != nullptr && verificarColisao(pJog1, pC))
            pC->sustentar(pJog1);
        if (pJog2 != nullptr && verificarColisao(pJog2, pC))//add Jog2
            pC->sustentar(pJog2);


        for (Inimigo *pI : LIs)
        {
            if (pI != nullptr && verificarColisao(pI, pC))
                pC->sustentar(pI);
                
            if (pJog2 != nullptr && verificarColisao(pJog2, pC))
            pC->sustentar(pJog2);

        }
    }
}

void Gerenciador_Colisoes::incluirInimigo (Inimigo *pI)
{
    if (pI == NULL)
        cerr << "Erro ao tentar incluir inimigo." << endl;
    else
        LIs.push_back(pI);
}
void Gerenciador_Colisoes::incluirObstaculo (Obstaculo *pO)
{
    if(pO == NULL)
        cerr << "Erro ao tentar incluir obstaculo." << endl;
    else
        LOs.push_back(pO);
}
void Gerenciador_Colisoes::incluirProjetil (Projetil *pP)
{
    if(pP == NULL)
        cerr << "Erro ao tentar incluir projetil." << endl;
    else
        LPs.insert(pP);
}
void Gerenciador_Colisoes::incluirJogador (Jogador *pJ)
{
    if (pJ == NULL)
        cerr << "Erro ao tentar incluir jogador." << endl;

    else if (pJog1 == nullptr)
        pJog1 = pJ;
    else
        pJog2 = pJ;
}
void Gerenciador_Colisoes::incluirChao (Chao *pC)
{
    if (pC == NULL)
        cerr << "Erro ao tentar incluir chao." << endl;
    else
        LCs.push_back(pC);
}


void Gerenciador_Colisoes::executar()
{
    tratarColisoesChao();
    tratarColisoesInimgsObstacs();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
}   
}