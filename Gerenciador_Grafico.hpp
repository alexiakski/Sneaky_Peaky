#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>

class Ente;
class Gerenciador_Grafico
{
    private:

        sf::RenderWindow janela;

    public:

        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        bool estaAberta();
        void processarEventos(); 
        void limpar();
        void desenhar(Ente* pE);
        void mostrar();
};

#endif