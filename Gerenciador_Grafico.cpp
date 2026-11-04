#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

Gerenciador_Grafico::Gerenciador_Grafico() : janela(sf::VideoMode(800,600), "Sneaky Peaky")
{
    janela.setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

bool Gerenciador_Grafico::estaAberta()
{
    return janela.isOpen();
}

void Gerenciador_Grafico::processarEventos()
{
    sf::Event evento;

    while (janela.pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
            janela.close();
    }
}
void Gerenciador_Grafico::limpar()
{
    janela.clear();
}

void Gerenciador_Grafico::desenhar(Ente* pE)
{
    if (pE != nullptr)
        janela.draw(*pE->getFigura());
}

void Gerenciador_Grafico::mostrar()
{
    janela.display();
}

sf::Texture* Gerenciador_Grafico::carregarTextura(const std::string& caminho, sf::IntRect area)
{
    string chave = caminho;
    if (area.width > 0)//adaptação para fundo
        chave += "#" + to_string(area.left) + "," + to_string(area.top) + "," + to_string(area.width) + "," + to_string(area.height);

    std::map<std::string, sf::Texture>::iterator it = texturas.find(chave);//devolve a posição no mapa

    if (it != texturas.end())
        return &(it->second);//devolve o valor - it->first é o caminho, it->second é a textura

    sf::Texture& tex = texturas[chave];//se não existir cria nova textura 

    if (!tex.loadFromFile(caminho, area))//se não achar
    {
        std::cout << "Erro ao carregar " << caminho << std::endl;
        texturas.erase(chave);    // remove a entrada vazia
        return nullptr;
    }
    return &tex;
}