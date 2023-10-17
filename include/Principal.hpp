#pragma once
#include "..\src\Jogador.cpp"

class Principal
{
private:
    sf::RenderWindow window;
    Jogador jogador;
public:
    Principal();
    ~Principal();
    void executar();
};

