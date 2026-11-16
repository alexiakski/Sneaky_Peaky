#include "stdafx.hpp"
#include "Samurai.hpp"
#include "Projetil.hpp"
#include "Lista_Entidades.hpp"
#include "Gerenciador_Colisoes.hpp"

Chefao::Chefao(float x, float y, ListaEntidades* pLista, Gerenciador_Colisoes* pGC)
        : Inimigo(x, y, 100, 50, 1, 5), pLista(pLista), pGC(pGC), recarga(0)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(0, 0, 96, 48));//só a primeira pose
}

Chefao::~Chefao()
{

}

void Chefao::salvar()
{

}

void Chefao::danificar (Jogador* pJog)
{
    if (pJog == nullptr)
        return;

    *pJog -= 2 * nivel_maldade;

    /*int dano = 2 * nivel_maldade;
    int vidasAtuais = pJog->getNumVidas();
    pJog->setNumVidas(vidasAtuais - dano);*/
    
    //pJog->reposicionar(this->getBounds());
}

void Chefao::executar()
{
    Inimigo::executar();

    recarga++;
    if (recarga >= 120)// a cada 2s
    {
        Projetil* pP = new Projetil (x+largura, y +10, 20, 20 ,1);
        pLista->incluir(pP);
        pGC->incluirProjetil(pP);
        recarga = 0;
    }
}