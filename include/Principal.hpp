#pragma once
#include "..\src\Jogador.cpp"
#include "..\src\Gerenciadores\GerenciadorGrafico.cpp"

class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Jogador jogador;
public:
    Principal();
    ~Principal();
    void executar();
};

