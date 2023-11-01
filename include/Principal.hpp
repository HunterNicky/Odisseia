#pragma once

#include "Entidades\Obstaculos\ObstaculoFacil.hpp"
#include "Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Gerenciadores\GerenciadorGrafico.hpp"
#include "Lista\ListaDeEntidades.hpp"
#include "Gerenciadores\GerenciadorDeColisao.hpp"
#include "Gerenciadores\GerenciadorFisico.hpp"
class Principal
{
private:
    static Gerenciadores::GerenciadorGrafico* pGrafico;
    sf::RenderWindow window;
    Lista::ListaDeEntidades LE;
    Entidades::Personagens::Jogador jogador;
    Entidades::Personagens::Inimigo inimigo;
    Gerenciadores::GerenciadorFisico gerenciadorFisico;
    Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
    Entidades::Obstaculos::ObstaculoFacil ObstFacil;
    Entidades::Obstaculos::ObstaculoFacil ObstFacil1;
    
public:
    Principal();
    ~Principal();
    void executar();
};

