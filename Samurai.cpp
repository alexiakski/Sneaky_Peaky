#include "stdafx.hpp"
#include "Samurai.hpp"
#include "Projetil.hpp"
#include "Lista_Entidades.hpp"
#include "Gerenciador_Colisoes.hpp"

using namespace Listas;
using namespace Gerenciadores;

namespace Entidades::Personagens 
{

Samurai::Samurai(float x, float y, ListaEntidades* pLista, Gerenciador_Colisoes* pGC)
        : Inimigo(x, y, 63, 35, 2, 3, 0.3f), pLista(pLista), pGC(pGC), recarga(0)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(13, 5, 70, 39));//só a primeira pose
}

Samurai::~Samurai()
{

}

void Samurai::salvar()
{
    salvarDataBuffer();
    buffer << recarga;
    ofstream("save/samurai.txt", ios::app) << buffer.str() << '\n';
}

void Samurai::danificar (Jogador* pJog)
{
    if (pJog != nullptr)
       pJog->sofrerAtaque(nivel_maldade);
}

void Samurai::executar()
{
    Inimigo::executar();

    recarga++;
    if (recarga >= 300)//a cada 5s
    {
        bool ladoD = (x + largura/2 > 400);//se está no lado direito da janela

        float vel = ladoD ? -2.0f : 2.0f; 
        float xTiro = ladoD ? x - 20 : x + largura;
        
        Projetil* pP = new Projetil (xTiro, y +10, 20, 20 ,1, vel);
        pLista->incluir(pP);
        pGC->incluirProjetil(pP);
        recarga = 0;
    }
}
}