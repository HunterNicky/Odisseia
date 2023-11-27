#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
class AnimacaoAtaque : public AnimacaoStrategy {
private:
  float variableTimeAttack;
  void updateAnimationFrame(double dt, float standardTime);
  void updateSpriteRect();
  
public:
  AnimacaoAtaque(Entidades::Entidade *entidade, std::string path,
                 const int numFrames, const sf::Vector2f escala);
  ~AnimacaoAtaque();
  void updateSprite(double dt, float standardTime);
  void changeTexture();
};
} // namespace Animacao