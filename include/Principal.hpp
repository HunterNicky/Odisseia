#pragma once

#include "Entidades\Obstaculos\ObstaculoFacil.hpp"
#include "Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
#include "Estados\MaquinaDeEstado.hpp"
#include "Estados\Fases\Fase1.hpp"

class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    static Estados::MaquinaDeEstado* pMaquinaDeEstado;
    sf::RenderWindow window;
    Lista::ListaDeEntidades LE;
public:
    Principal();
    ~Principal();
    void executar();
};