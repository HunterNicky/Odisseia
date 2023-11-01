#pragma once
#include "Entidades\Obstaculos\ObstaculoFacil.hpp"
#include "Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
#include "Fases\Fase1.hpp"
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Lista::ListaDeEntidades LE;
    Fases::Fase1 primeiraFase;
public:
    Principal();
    ~Principal();
    void executar();
};

