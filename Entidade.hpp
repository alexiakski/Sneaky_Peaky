#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include "stdafx.hpp"
#include "Ente.hpp"

namespace Entidades 
{
class Entidade : public Ente
{
    protected:

        float x, y;
        float largura, altura;
        float gravidade = 0.5f;
        bool ativo;//se está vivo
        ostringstream buffer;

        void salvarDataBuffer();

    public:
    
        Entidade(float x, float y, float largura, float altura);
        virtual ~Entidade();

        float getX() const;
        float getY() const;
        float getLargura() const;
        float getAltura() const;
        sf::FloatRect getBounds() const override;

        bool getAtivo() const;
        void setAtivo(bool ativo);

        void setPosicao(float x, float y);

        virtual void executar() = 0;

        virtual void salvar() = 0;
};
}

#endif