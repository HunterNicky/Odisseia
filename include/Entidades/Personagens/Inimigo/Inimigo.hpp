#include "..\Jogador\Jogador.hpp"

namespace Entidades{
    namespace Personagens{
        class Inimigo : public Personagem{
        protected:
            Entidades::Personagens::Jogador *pJogador;

        public:
            Inimigo(sf::Vector2f pos, sf::Vector2f size, int id);
            ~Inimigo();
            
        };
    }
}