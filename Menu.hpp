#ifndef MENU_HPP
#define MENU_HPP

#include "Ente.hpp"
class Menu : public Ente
{
    private:

        int tela, numJog, numFase, pontos;
        bool teclaPressionada;

    public:

        Menu();
        ~Menu();

        int getFase() const;
        int getNumJog() const;
        bool getPausado() const;
        void pausar();
        void executar();
        void fimDeJogo(int pontos);

    private:

        void escolher();
        void escrever(const string texto, float y);
};

#endif