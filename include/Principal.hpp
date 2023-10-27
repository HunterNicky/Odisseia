#pragma once
#include "Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Entidades::Personagens::Jogador jogador;
    Entidades::Personagens::Inimigo inimigo;
    Lista::ListaDeEntidades LE;
public:
    Principal();
    ~Principal();
    void executar();
};

