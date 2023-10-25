#pragma once
#include "Entidades\Personagens\Jogador\Jogador.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
;
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Entidades::Personagens::Jogador jogador;
public:
    Principal();
    ~Principal();
    void executar();
};

