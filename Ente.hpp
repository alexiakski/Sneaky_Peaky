#ifndef ENTE_HPP
#define ENTE_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>

namespace Gerenciadores {class Gerenciador_Grafico;}
class Ente
{
    protected:

        int id;
        static int cont;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::RectangleShape* pFig;//trocar quando escolher sprite

    public:

        Ente();
        virtual ~Ente();

        int getId() const;
        sf::RectangleShape* getFigura() const;
        virtual sf::FloatRect getBounds() const;
    
        virtual void executar() = 0;
        virtual void desenhar();
        void static setGG(Gerenciadores::Gerenciador_Grafico *pGG);

        void setTextura(const std::string& caminho, sf::IntRect recorte = sf::IntRect()); //usa a imagem inteira ou um recorte
};

#endif
