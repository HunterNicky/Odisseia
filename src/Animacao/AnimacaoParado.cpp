#include "Animacao/AnimacaoParado.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <algorithm>

namespace Animacao {

AnimacaoParado::AnimacaoParado(Entidades::Entidade *entidade, std::string path,
                               int numFrames, sf::Vector2f escala)
    : AnimacaoStrategy(entidade, numFrames, escala), deepBreath(0.f) {
  textura = pGrafico->loadTexture(path);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setTexture(textura);
}

AnimacaoParado::~AnimacaoParado(){};

void AnimacaoParado::updateSprite(double dt, float standardTime) {
  deepBreath = std::min(
      static_cast<Entidades::Personagens::Personagem *>(entidade)
              ->getNum_vidas() *
          0.3f,
      static_cast<Entidades::Personagens::Jogador *>(entidade)->getEstamina() <
              0.3f
          ? 1.f
          : static_cast<Entidades::Personagens::Jogador *>(entidade)
                ->getEstamina());
  updateAnimationFrame(dt, standardTime);
  updateSpriteRect();
  entidade->getBody()->setTextureRect(rectSize);
}

void AnimacaoParado::updateAnimationFrame(double dt, float standardTime) {
  actualFrame += dt / deepBreath;

  if (actualFrame >= standardTime) {
    actualFrame -= standardTime;
    actualImage = (actualImage + 1) % numFrames;
  }
}

void AnimacaoParado::updateSpriteRect() {
  rectSize.left = actualImage * std::abs(rectSize.width);

  if (entidade->getPos().x < entidade->getPrevPos().x) {
    rectSize.left += std::abs(rectSize.width);
    rectSize.width = -std::abs(rectSize.width);
  } else {
    rectSize.width = std::abs(rectSize.width);
  }
}

void AnimacaoParado::changeTexture() {
  entidade->getBody()->setScale(escala);
  entidade->getBody()->setTexture(textura);
}
} // namespace Animacao