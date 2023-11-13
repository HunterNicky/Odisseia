
#include "..\Personagens\Personagem.hpp"
#include <iostream>

namespace Entidades{
    class Projetil: public Entidade{
    private:
        static int dano;
        sf::Vector2f vel;
        Entidades::Personagens::Personagem* pPers;

    public:
        Projetil(const sf::Vector2f pos, const Entidades::ID id, const bool direita);
        ~Projetil();
        void tratarColisao(Entidades::Entidade* entidade);
        void verificaSolo(const sf::Vector2f mtv);
        void setPersonagem(Entidades::Personagens::Personagem* pPers);
        void draw();
        void executar();
        void update();
    };
}