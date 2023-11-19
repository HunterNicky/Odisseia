#pragma once

#include "Inimigo.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM_INIMIGO_FACIL_X 30.f
#define TAM_INIMIGO_FACIL_Y 40.0f
#define RAIO 200.0f

namespace Entidades{
    namespace Personagens{
        class InimigoFacil : public Inimigo{
        private:
            int raivosidade;
            int dano;
            void inicializa();
        public:
            InimigoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            InimigoFacil(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~InimigoFacil();
            void operator--(const int dano);
            void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void movimentoAleatorio();
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
            void salvar(std::ostringstream* entrada);
        };
    }
}