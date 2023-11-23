#include "Animacao/AnimacaoAndar.hpp"
#include <iostream>

namespace Animacao {

AnimacaoAndar::AnimacaoAndar(Entidades::Entidade *entidade, std::string path,
                             std::string path2, const int numFrameWalk,
                             const int numFrameRun,
                             const sf::Vector2f escalaRun,
                             const sf::Vector2f escalaWalk)
    : AnimacaoStrategy(entidade, numFrameWalk, escalaWalk),
      numFrameWalk(numFrameWalk), numFrameRun(numFrameRun), actualFrame(0.f) {
  textura = pGrafico->loadTexture(path);
  run = pGrafico->loadTexture(path2);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setTexture(textura);
}

AnimacaoAndar::~AnimacaoAndar(){};

void AnimacaoAndar::updateSprite(double dt, float standardTime) {
  updateRun();
  updateAnimationFrame(dt, standardTime);
  updateSpriteRect();
  entidade->getBody()->setTextureRect(rectSize);
}

void AnimacaoAndar::updateAnimationFrame(double dt, float standardTime) {
  actualFrame += dt * std::abs(entidade->getVel().x);

  if (actualFrame >= standardTime) {
    actualFrame -= standardTime;
    actualImage = (actualImage + 1) % numFrames;
  }
}

void AnimacaoAndar::updateSpriteRect() {
  rectSize.left = actualImage * std::abs(rectSize.width);

  if (entidade->getPos().x < entidade->getPrevPos().x) {
    rectSize.left += std::abs(rectSize.width);
    rectSize.width = -std::abs(rectSize.width);
  } else {
    rectSize.width = std::abs(rectSize.width);
  }
}

void AnimacaoAndar::updateRun() {
  if (std::abs(entidade->getForca().x) > 5050.f) {
    numFrames = numFrameRun;
    rectSize.width = (run->getSize().x / numFrames);
    rectSize.height = (run->getSize().y);
    rectSize.left = 0;
    entidade->getBody()->setScale(escalaRun);
    changeTexture(run);
  } else {
    numFrames = numFrameWalk;
    rectSize.width = (textura->getSize().x / numFrames);
    rectSize.height = (textura->getSize().y);
    rectSize.left = 0;
    entidade->getBody()->setScale(escala);
    changeTexture(textura);
  }
}

void AnimacaoAndar::changeTexture(sf::Texture *corrida) {
  entidade->getBody()->setTexture(corrida);
}

void AnimacaoAndar::changeTexture() {
  entidade->getBody()->setTexture(textura);
}

} // namespace Animacao