#pragma once
#include "..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
;
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Entidades::Personagens::Jogador jogador; 
    Entidades::Personagens::Inimigo inimigo;
public:
    Principal();
    ~Principal();
    void executar();
};

