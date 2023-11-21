#pragma once

#include "..\Personagens\Personagem.hpp"
#include "Entidades/Personagens/Inimigo/InimigoMedio.hpp"
//#include "Entidades/Personagens/Personagem.hpp"
//#include "Estados/Fases/Fase.hpp"
#include <iostream>

namespace Entidades{
    class Projetil: public Entidade{
    private:
        static int dano;
        //Personagens::InimigoMedio* pInim;
        sf::Vector2f vel;
        bool onFloor;
    public:
        Projetil(const sf::Vector2f pos, const Entidades::ID id, const bool direita);
        Projetil(nlohmann::json atributos, const int pos, const Entidades::ID id);
        ~Projetil();
        void tratarColisao(Entidades::Entidade* entidade);
        void verificaSolo(const sf::Vector2f mtv);  
        void move();
        void draw();
        void executar();
        void update();
        void salvar(std::ostringstream* entrada);
    };
}