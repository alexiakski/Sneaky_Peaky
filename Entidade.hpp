#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include "stdafx.hpp"
#include "Ente.hpp"

class Entidade : public Ente
{
    protected:

        float x, y;
        float largura, altura;
        //ostream buffer; salvamento-requisito 10

    public:
    
        Entidade(float x, float y, float largura, float altura);
        virtual ~Entidade();

        float getX() const;
        float getY() const;
        float getLargura() const;
        float getAltura() const;
        //ostream getBuffer();
        sf::FloatRect getBounds() const override;   

        virtual void executar() = 0;

        void salvarDataBuffer();
        virtual void salvar() = 0;
};

#endif