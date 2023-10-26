#pragma once
#include "Entidades\Personagens\Jogador\Jogador.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Entidades::Personagens::Jogador jogador;
    Lista::ListaDeEntidades LE;
public:
    Principal();
    ~Principal();
    void executar();
};

