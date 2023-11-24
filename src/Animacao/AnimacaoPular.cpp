#include "Animacao/AnimacaoPular.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <iostream>

namespace Animacao {

AnimacaoPular::AnimacaoPular(Entidades::Entidade *entidade, std::string path,
                             std::string path2, const int numFrameLowJump,
                             const int numFrameHighJump,
                             const sf::Vector2f escalaLowJump,
                             const sf::Vector2f escalaHighJump)
    : AnimacaoStrategy(entidade, numFrameLowJump, escalaHighJump),
      numFrameHighJump(numFrameHighJump), numFrameLowJump(numFrameLowJump),
      escalaLowJump(escalaLowJump), actualFrame(0.f), jumpTime(0.f) {

  textura = pGrafico->loadTexture(path);
  HighJump = pGrafico->loadTexture(path2);
  rectSize.width = (textura->getSize().x / numFrames);
  rectSize.height = (textura->getSize().y);
  entidade->getBody()->setTexture(textura);
}

AnimacaoPular::~AnimacaoPular(){};

void AnimacaoPular::updateSprite(double dt, float standardTime) {
  jumpTime = static_cast<Entidades::Personagens::Personagem *>(entidade)
                 ->getJumpTime();
  updateJump(dt);
  updateAnimationFrame(dt, standardTime);
  updateSpriteRect();
  entidade->getBody()->setTextureRect(rectSize);
}

void AnimacaoPular::updateAnimationFrame(double dt, float standardTime) {
  actualFrame += dt - jumpTime / (numFrames * 4);

  if (actualFrame >= standardTime) {
    actualFrame -= standardTime;
    actualImage = (actualImage + 1) % numFrames;
  }
}

void AnimacaoPular::updateSpriteRect() {
  rectSize.left = actualImage * std::abs(rectSize.width);

  if (entidade->getPos().x < entidade->getPrevPos().x) {
    rectSize.left += std::abs(rectSize.width);
    rectSize.width = -std::abs(rectSize.width);
  } else {
    rectSize.width = std::abs(rectSize.width);
  }
}

void AnimacaoPular::updateJump(double dt) {
  if (jumpTime > 2.5f * dt) {
    numFrames = numFrameHighJump;
    rectSize.width = (HighJump->getSize().x / numFrames);
    rectSize.height = (HighJump->getSize().y);
    rectSize.left = 0;
    entidade->getBody()->setScale(escala);
    changeTexture(HighJump);
  } else {
    numFrames = numFrameLowJump;
    rectSize.width = (textura->getSize().x / numFrames);
    rectSize.height = (textura->getSize().y);
    rectSize.left = 0;
    entidade->getBody()->setScale(escalaLowJump);
    changeTexture(textura);
  }
}

void AnimacaoPular::changeTexture(sf::Texture *pulo) {
  entidade->getBody()->setTexture(pulo);
}

void AnimacaoPular::changeTexture() {
  entidade->getBody()->setTexture(textura);
}

} // namespace Animacao