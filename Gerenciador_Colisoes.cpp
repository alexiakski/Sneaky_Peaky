#include "Gerenciador_Colisoes.hpp"
#include "Ente.hpp"

Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), LPs(), LCs(), pJog1(nullptr)
{

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();
    pJog1 = nullptr;
}

const bool Gerenciador_Colisoes::verificarColisao (Ente *pE1, Ente *pE2)
{
    if(pE1 == NULL || pE2 == NULL)
        return false;

    return (pE1->getBounds()).intersects(pE2->getBounds());
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs ()
{
    if (pJog1 == nullptr) return;

        for (Obstaculo *pO : LOs)
        {
            if (pO != nullptr && verificarColisao(pJog1, pO))
            {
                //pJog1->obstaculizar(pO);
                pO->obstaculizar(pJog1);
            }
        }
}
void Gerenciador_Colisoes::tratarColisoesJogsInimgs ()
{
    if (pJog1 == nullptr) return;

    for (size_t i = 0; i < LIs.size(); i++)
    {
        Inimigo *pI = LIs[i];
        if (pI != nullptr && verificarColisao(pJog1, pI))
        {
            pJog1->colidir(pI);
        }
    }
}
void Gerenciador_Colisoes::tratarColisoesJogsProjeteis ()
{
    if (pJog1 == nullptr) return;

    for (Projetil *pP : LPs)
    {
        if (pP != nullptr && pP->getAtivo() && verificarColisao(pJog1, pP))
        {
            pP->colidir(pJog1);
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

        for (Inimigo *pI : LIs)
        {
            if (pI != nullptr && verificarColisao(pI, pC))
                pC->sustentar(pI);
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
    else
        pJog1 = pJ;
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
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
}   
