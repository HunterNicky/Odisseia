#pragma once

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
    Estados::Fases::Fase1 primeiraFase;
public:
    Principal();
    ~Principal();
    void executar();
};