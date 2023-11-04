#pragma once

#include "Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Fases\Fase1.hpp"

class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Fases::Fase1 primeiraFase;
public:
    Principal();
    ~Principal();
    void executar();
};

