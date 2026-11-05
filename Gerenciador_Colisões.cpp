#include "Gerenciador_Colisoes.hpp"
#include "Ente.hpp"

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
    LIs();
    LOs();
    LPs();
}
Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

const bool Gerenciador_Colisoes::verificarColisao (Ente *pE1, Ente *pE2)
{
    if(pE1 == NULL || pE2 == NULL)
        return false;

    return (pE1->getBounds()).intersects(pE2->getBounds());
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs ()
{

}
void Gerenciador_Colisoes::tratarColisoesJogsInimgs ()
{
    
}
void Gerenciador_Colisoes::tratarColisoesJogsProjeteis ()
{

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
        LPs.push_back(pP);
}


void Gerenciador_Colisoes::executar()
{

}
