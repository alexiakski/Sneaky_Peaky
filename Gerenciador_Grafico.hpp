#ifndef GERENCIADOR_GRAFICO_HPP
#define GERENCIADOR_GRAFICO_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
class Gerenciador_Grafico
{
    private:

        sf::RenderWindow janela;
        std::map<std::string, sf::Texture> texturas;//para guardar as imagens - só precisa carregar uma vez

    public:

        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        bool estaAberta() const;
        void processarEventos(); 
        void limpar();
        void desenhar(const sf::Drawable& d);
        void mostrar();
        void fechar();

        sf::Texture* carregarTextura(const std::string& caminho, sf::IntRect area = sf::IntRect());
};
}
#endif