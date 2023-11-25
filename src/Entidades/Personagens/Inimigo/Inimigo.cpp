#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "Entidades/Personagens/Inimigo/Inimigo.hpp"

namespace Entidades {
namespace Personagens {
Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f size,
                 const Entidades::ID id, Jogador *pJog)
    : Personagem(pos, size, id), pJogador(pJog) {
  inicializaVidaIni();
}

Inimigo::~Inimigo() {
  if (barraVida != nullptr) {
    delete barraVida;
  }
}

void Inimigo::inicializaVidaIni() {
  barraVida = new sf::RectangleShape();
  barraVida->setSize(sf::Vector2f(BARRA_VIDA_JOG_X, BARRA_VIDA_JOG_Y));
  sf::Texture *texturaBarra = new sf::Texture();
  texturaBarra->loadFromFile("data\\Vida\\VidaInimigo.png");
  barraVida->setTexture(texturaBarra);
}
} // namespace Personagens
} // namespace Entidades
