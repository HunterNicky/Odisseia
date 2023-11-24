#include "Animacao/AnimacaoAtaque.hpp"
#include "Animacao/AnimacaoStrategy.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Animacao {
AnimacaoAtaque::AnimacaoAtaque(Entidades::Entidade *entidade, std::string path,
                               const int numFrames, const sf::Vector2f escala)
    : AnimacaoStrategy(entidade, numFrames, escala), actualFrame(0.f) {
  textura = pGrafico->loadTexture(path);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setScale(escala);
  entidade->getBody()->setTexture(textura);
}

AnimacaoAtaque::~AnimacaoAtaque() {}

void AnimacaoAtaque::updateSprite(double dt, float standardTime) {
  updateAnimationFrame(dt, standardTime);
  updateSpriteRect();
  entidade->getBody()->setScale(escala);
  entidade->getBody()->setTextureRect(rectSize);
}

void AnimacaoAtaque::updateAnimationFrame(double dt, float standardTime) {
  actualFrame += dt;

  if (actualFrame >= standardTime) {
    actualFrame -= standardTime;
    actualImage = (actualImage + 1) % numFrames;
    if (actualImage == 0) {
      static_cast<Entidades::Personagens::Personagem *>(entidade)->setAtaque(
          false);
    }
  }
}

void AnimacaoAtaque::updateSpriteRect() {
  rectSize.left = actualImage * std::abs(rectSize.width);

  if (entidade->getPos().x < entidade->getPrevPos().x) {
    rectSize.left += std::abs(rectSize.width);
    rectSize.width = -std::abs(rectSize.width);
  } else {
    rectSize.width = std::abs(rectSize.width);
  }
}

void AnimacaoAtaque::changeTexture() {
  entidade->getBody()->setScale(escala);
  entidade->getBody()->setTexture(textura);
}

} // namespace Animacao