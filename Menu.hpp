#ifndef MENU_HPP
#define MENU_HPP

#include "Ente.hpp"
class Menu : public Ente
{
    private:

        int tela, numJog, numFase, pontos, faseVencida, telaFinal;
        bool teclaPressionada;
        string nome;

        multimap<int, string, greater<int>> ranking;

    public:

        Menu();
        ~Menu();

        int getFase() const;
        int getNumJog() const;
        bool getPausado() const;
        void pausar();
        void executar();
        void fimDeJogo(int pontos, bool venceu);

    private:

        void escolher();
        void escrever(const string texto, float y);
};

#endif