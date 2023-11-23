#include "Inimigo.hpp"

#define TAM_INIMIGO_DIF_X 60.0f
#define TAM_INIMIGO_DIF_Y 96.0f
namespace Entidades{
    namespace Personagens{
        class Samurai: public Inimigo{
        private:
            void inicializa();
        public: 
            Samurai(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            Samurai(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog);
            ~Samurai();
            void operator--(const int dano);
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