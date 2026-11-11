#ifndef GERENCIADOR_COLISOES_HPP
#define GERENCIADOR_COLISOES_HPP

#include "stdafx.hpp"
#include "Ente.hpp"
#include "Entidade.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Projetil.hpp"
#include "Chao.hpp"

class Gerenciador_Colisoes
{
    private:

        vector<Inimigo*> LIs;
        list <Obstaculo*> LOs;
        set <Projetil*> LPs;
        vector <Chao*> LCs;
        Jogador *pJog1;

    public:

       Gerenciador_Colisoes();
       ~Gerenciador_Colisoes();
       
       const bool verificarColisao (Ente *pE1, Ente *pE2);
       void tratarColisoesJogsObstacs ();
       void tratarColisoesJogsInimgs ();
       void tratarColisoesJogsProjeteis ();
       void incluirInimigo (Inimigo *pI);
       void incluirObstaculo (Obstaculo *pO);
       void incluirProjetil (Projetil *pP);
       void incluirJogador (Jogador *pJ);
       void tratarColisoesChao();
       void incluirChao (Chao *pC);

       void executar();
};

#endif
