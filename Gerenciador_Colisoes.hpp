#include "stdafx.hpp"
#include "Ente.hpp"
#include "Entidade.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Projetil.hpp"

class Gerenciador_Colisoes
{
    private:

        vector<Inimigo*> LIs;
        list <Obstaculo*> LOs;
        set <Projetil*> LPs;
        
        Jogador *pJog1;

    public:

       const bool verificarColisao (Ente *pE1, Ente *pE2);
       void tratarColisoesJogsObstacs ();
       void tratarColisoesJogsInimgs ();
       void tratarColisoesJogsProjeteis ();
       void incluirInimigo (Inimigo *pI);
       void incluirObstaculo (Obstaculo *pO);
       void incluirProjetil (Projetil *pP);

       void executar();
};