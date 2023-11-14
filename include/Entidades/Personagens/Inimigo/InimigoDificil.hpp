#include "Inimigo.hpp"

namespace Entidades{
    namespace Personagens{
        class InimigoDificil: public Inimigo{
        private:
            void inicializa();
        public: 
            InimigoDificil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~InimigoDificil();
            void operator--(const int dano);
            void movimentoAleatorio();
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;

        };
    }
}