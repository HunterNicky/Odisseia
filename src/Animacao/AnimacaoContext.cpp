#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"

namespace Animacao {
AnimacaoContext::AnimacaoContext() : strategy(nullptr), standardTime(0.f) {}

AnimacaoContext::~AnimacaoContext() { strategy = nullptr; }

void AnimacaoContext::setStrategy(AnimacaoStrategy *strategy,
                                  const float standardTime) {
  this->strategy = strategy;
  this->standardTime = standardTime;
  strategy->changeTexture();
}

void AnimacaoContext::updateStrategy(double dt) {
  if (strategy != nullptr)
    strategy->updateSprite(dt, standardTime);
}
} // namespace Animacao
