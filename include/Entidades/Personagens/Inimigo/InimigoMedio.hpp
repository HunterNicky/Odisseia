#pragma once

#include "Fases/Fase.hpp"
#include "Inimigo.hpp"
#include <math.h>

#define TAM_INIMIGO_MED_X 60.0f
#define TAM_INIMIGO_MED_Y 96.0f
namespace Fases{
    class Fase;
}

#define RANGE 200.0f
namespace Entidades{
    namespace Personagens{
        class InimigoMedio: public Inimigo{
        private:
            Fases::Fase* pFase;
            bool ProjAtivo;
            void inicializa();
        public:
            InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Fases::Fase* pFase);
            InimigoMedio(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~InimigoMedio();
            void operator--(const int dano);
            void movimentoAleatorio();
            void atirarProjetil(sf::Vector2f pos, const bool direita);
            void deletarProjetil();
            const bool getProjAtivo();
            void move();
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
            void salvar(std::ostringstream* entrada);
        };
    }
}