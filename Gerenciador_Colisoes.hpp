#ifndef GERENCIADOR_COLISOES_HPP
#define GERENCIADOR_COLISOES_HPP

#include "stdafx.hpp"
#include "Ente.hpp"
#include "Entidade.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Projetil.hpp"
#include "Chao.hpp"

namespace Gerenciadores
{
class Gerenciador_Colisoes
{
    private:

        vector<Entidades::Personagens::Inimigo*> LIs;
        list <Entidades::Obstaculos::Obstaculo*> LOs;
        set <Entidades::Projetil*> LPs;
        vector <Entidades::Chao*> LCs;
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;

    public:

       Gerenciador_Colisoes();
       ~Gerenciador_Colisoes();
       
       bool verificarColisao (Entidades::Entidade *pE1, Entidades::Entidade *pE2);
       void tratarColisoesJogsObstacs ();
       void tratarColisoesJogsInimgs ();
       void tratarColisoesInimgsObstacs ();
       bool todosInimigosMortos() const;
       void tratarColisoesJogsProjeteis ();
       void incluirInimigo (Entidades::Personagens::Inimigo *pI);
       void incluirObstaculo (Entidades::Obstaculos::Obstaculo *pO);
       void incluirProjetil (Entidades::Projetil *pP);
       void incluirJogador (Entidades::Personagens::Jogador *pJ);
       void tratarColisoesChao();
       void incluirChao (Entidades::Chao *pC);

       void executar();
};
}

#endif
