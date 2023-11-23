#pragma once

//#include "Entidades/Laser/Laser.hpp"
#include "Inimigo.hpp"
#include <math.h>

#define TAM_INIMIGO_MED_X 60.0f
#define TAM_INIMIGO_MED_Y 96.0f
namespace Fases{
    class Fase;
}

#define RANGE 200.0f
namespace Entidades{
    class Laser;
    namespace Personagens{
        class Viajante: public Inimigo{
        private:
            Entidades::Laser* pProj;
            bool ProjAtivo;
            bool direita;
            void inicializa();
        public:
            Viajante(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Entidades::Laser* proj);
            Viajante(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~Viajante();
            void operator--(const int dano);
            void movimentoAleatorio();
            void atirarProjetil(sf::Vector2f pos, const bool direita);
            void deletarProjetil();
            void setProj(Entidades::Laser* pProj);
            const bool getProjAtivo();
            const bool getDirecaoProj();
            void move();
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
            void salvar(std::ostringstream* entrada);
        };
    }
}