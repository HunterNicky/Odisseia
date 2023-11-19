#pragma once

#include "Animacao/AnimacaoParado.hpp"
#include "Animacao/AnimacaoPular.hpp"
#include "Entidades/Entidade.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoStrategy.hpp"
#include "Entidades/Personagens/Personagem.hpp"

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
            ~Jogador();
            void operator--(const int dano);
            const float getEstamina() const;
            void move();
            void neutralizarInimigo(Entidade* pInimigo);
            void tratarColisao(Entidade* entidade);
            void pular();
            void correr();
            void direcionar(const bool side);
            void parar();
            void executar();
            void update();
        };
    }
}
