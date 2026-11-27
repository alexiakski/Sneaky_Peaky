#include "stdafx.hpp"
#include "Jogo.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    try
    {
        Jogo jogo;
        jogo.executar();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
//para compilar e rodar: ctrl + shift + b