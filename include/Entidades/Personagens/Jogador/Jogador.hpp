#pragma once

#include "Animacao/AnimacaoParado.hpp"
#include "Animacao/AnimacaoPular.hpp"
#include "Entidades/Entidade.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoStrategy.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <vector>

#define TAM_X_JOGADOR 60.0f
#define TAM_Y_JOGADOR 96.0f
#define VEL_X_JOGADOR 0.0f
#define VEL_Y_JOGADOR 0.0f
#define CAMINHO_ANDAR_JOG "data\\Sprites\\player\\playerwalk.png"
#define CAMINHO_CORRER_JOG "data\\Sprites\\player\\playerrun.png"
#define CAMINHO_PARADO_JOG "data\\Sprites\\player\\playeridle.png"
#define CAMINHO_PULAR_JOG "data\\Sprites\\player\\playerjump.png"
#define CAMINHO_SPIN_JOG "data\\Sprites\\player\\playerspin.png"
#define BARRA_VIDA_JOG_X 300.0f
#define BARRA_VIDA_JOG_Y 80.0f

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem {
        private:
            void inicializa();
            float estamina;
            Animacao::AnimacaoAndar andar;
            Animacao::AnimacaoParado parado;
            Animacao::AnimacaoPular pulando;
            Animacao::AnimacaoContext contextoAnimacao;
            
        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            Jogador(nlohmann::json atributos, const int pos, const Entidades::ID id);
            ~Jogador();
            void operator--(const int dano);
            const float getEstamina() const;
            void animacao();
            void inicializarBarraDeVida();
            void atualizarBarraDeVida();
            void move();
            void neutralizarInimigo(Entidade* pInimigo);
            void tratarColisao(Entidade* entidade);
            void pular();
            void correr();
            void direcionar(const bool side);
            void parar();
            void executar();
            void update();
            void salvar(std::ostringstream* entrada);
        };
    }
}
