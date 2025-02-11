#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
class AnimacaoBloco : public AnimacaoStrategy {
private:
  float randomTimeChange;
  void updateAnimationFrame(double dt, float standardTime);
  void updateSpriteRect();

public:
  AnimacaoBloco(Entidades::Entidade *entidade, std::string path, int numFrames,
                const sf::Vector2f escala);
  AnimacaoBloco(Entidades::Entidade *entidade, int numFrames,
                const sf::Vector2f escala);
  ~AnimacaoBloco();
  void setTexture(const std::string path);
  void updateSprite(double dt, float standardTime);
  void changeTexture();
};
} // namespace Animacao