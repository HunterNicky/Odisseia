#pragma once

#include "..\Personagem.hpp"
#include "Entidades/Entidade.hpp"
#include "Estados/Fases/json.hpp"
#include <vector>

#define TAM_X_JOGADOR 50.0f
#define TAM_Y_JOGADOR 50.0f
#define VEL_X_JOGADOR 0.0f
#define VEL_Y_JOGADOR 0.0f

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem {
        private:
            void inicializa();
        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            Jogador(nlohmann::json atributos, const int pos, const Entidades::ID id);
            ~Jogador();
            void operator--(const int dano);
            void move();
            void neutralizarInimigo(Entidade* pInimigo);
            void tratarColisao(Entidade* entidade);
            void pular();
            void direcionar(const bool side);
            void parar();
            void executar();
            void update();
            void salvar(std::ostringstream* entrada);
        };
    }
}
