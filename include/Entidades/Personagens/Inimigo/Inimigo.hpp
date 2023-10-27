#include "..\Jogador\Jogador.hpp"

namespace Entidades{
    namespace Personagens{
        class Inimigo : public Personagem{
        protected:
            Jogador *pJogador;
            void inicializa();
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f size, int id, Jogador* pJog);
            ~Inimigo();
            void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void move();
            void executar();
            void update();
        };
    }
}