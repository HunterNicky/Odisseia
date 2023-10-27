#pragma once
#include "..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
#include "Gerenciadores\GerenciadorDeColisao.hpp"
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Entidades::Personagens::Jogador jogador;
    Entidades::Personagens::Inimigo inimigo;
    Lista::ListaDeEntidades LE;
    Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
public:
    Principal();
    ~Principal();
    void executar();
};

