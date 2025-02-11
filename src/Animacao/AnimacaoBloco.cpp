#include "Animacao/AnimacaoBloco.hpp"

namespace Animacao {

AnimacaoBloco::AnimacaoBloco(Entidades::Entidade *entidade, std::string path,
                             int numFrames, const sf::Vector2f escala)
    : AnimacaoStrategy(entidade, numFrames, escala) {
  std::srand(time(NULL));
  randomTimeChange = (std::rand() % 4 + 1) / 5.f;
  textura = pGrafico->loadTexture(path);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setTexture(textura);
}
AnimacaoBloco::AnimacaoBloco(Entidades::Entidade *entidade, int numFrames,
                             const sf::Vector2f escala)
    : AnimacaoStrategy(entidade, numFrames, escala) {
  std::srand(time(NULL));
  randomTimeChange = (std::rand() % 4 + 1) / 5.f;
}

AnimacaoBloco::~AnimacaoBloco() {}

void AnimacaoBloco::setTexture(const std::string path) {
  textura = pGrafico->loadTexture(path);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setTexture(textura);
}
void AnimacaoBloco::updateSprite(double dt, float standardTime) {
  updateAnimationFrame(dt, standardTime);
  updateSpriteRect();
  entidade->getBody()->setTextureRect(rectSize);
}

void AnimacaoBloco::updateAnimationFrame(double dt, float standardTime) {
  actualFrame += dt;

  if (actualFrame >= standardTime + randomTimeChange) {
    actualFrame -= standardTime;
    actualImage = (actualImage + 1) % numFrames;
  }
}

void AnimacaoBloco::updateSpriteRect() {
  rectSize.left = actualImage * std::abs(rectSize.width);

  if (entidade->getPos().x < entidade->getPrevPos().x) {
    rectSize.left += std::abs(rectSize.width);
    rectSize.width = -std::abs(rectSize.width);
  } else {
    rectSize.width = std::abs(rectSize.width);
  }
}

void AnimacaoBloco::changeTexture() {
  entidade->getBody()->setScale(escala);
  entidade->getBody()->setTexture(textura);
}
} // namespace Animacao