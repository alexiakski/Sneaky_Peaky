#ifndef MENU_HPP
#define MENU_HPP

#include "Ente.hpp"
class Menu : public Ente
{
    private:

        int tela, numJog, numFase;
        bool teclaPressionada;

    public:

        Menu();
        ~Menu();

        int getFase() const;
        void executar();

    private:

        void escolher();
        void escrever(string texto, float y);
};

#endif