#pragma once

#include "..\Jogador\Jogador.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include "Lista/ListaDeEntidades.hpp"

namespace Entidades{
    namespace Personagens{
        class Inimigo : public Personagem{
        protected:
            Entidades::Personagens::Jogador *pJogador;
            int nivel_maldade;
            int moveAleatorio;
            float raio;
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~Inimigo();
            virtual void inicializa() = 0;
            virtual void operator--(const int dano) = 0;
            virtual void movimentoAleatorio() = 0;
            virtual void move() = 0;
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void salvar(std::ostringstream* entrada) = 0;
        };
    }
}