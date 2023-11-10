
#include "..\Personagens\Personagem.hpp"
#include <iostream>

namespace Entidades{
    class Projetil: public Entidade{
    private:
        static int dano;
        int vel;
        Entidades::Personagens::Personagem* pPers;

    public:
        Projetil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
        ~Projetil();
        void tratarColisao(Entidades::Entidade* entidade);
        void verificaSolo(const sf::Vector2f mtv);
        void draw();
        void executar();
        void update();
    };
}