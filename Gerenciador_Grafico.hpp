#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>
#include <map>//para guardar as imagens - só precisa carregar uma vez


class Ente;
class Gerenciador_Grafico
{
    private:

        sf::RenderWindow janela;
        std::map<std::string, sf::Texture> texturas;

    public:

        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        bool estaAberta();
        void processarEventos(); 
        void limpar();
        void desenhar(Ente* pE);
        void mostrar();

        sf::Texture* carregarTextura(const std::string& caminho);
};

#endif