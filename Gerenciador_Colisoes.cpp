#include "Gerenciador_Colisoes.hpp"
#include "Ente.hpp"

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
    LIs();
    LOs();
    LPs();
    pJog1(nullptr);
}
Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
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
            pJog1->obstaculizar(pO);
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


void Gerenciador_Colisoes::executar()
{
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsProjeteis();
}   
