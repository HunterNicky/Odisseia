#include "Animacao/AnimacaoStrategy.hpp"
#include "Entidades/Entidade.hpp"

namespace Animacao {
Gerenciadores::GerenciadorGrafico *AnimacaoStrategy::pGrafico =
    Gerenciadores::GerenciadorGrafico::getInstance();

AnimacaoStrategy::AnimacaoStrategy(Entidades::Entidade *entidade, int numFrames,
                                   const sf::Vector2f escala)
    : entidade(entidade), rectSize(), textura(nullptr), escala(escala),
      actualFrame(1.f), actualImage(0), numFrames(numFrames) {}

AnimacaoStrategy::~AnimacaoStrategy() { entidade = nullptr; }

void AnimacaoStrategy::updateSprite(double dt, float standardTime) {}
} // namespace Animacao