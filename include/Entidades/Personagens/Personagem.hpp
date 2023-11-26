#pragma once

#include "..\Entidade.hpp"
#include "Entidades/Entidade.hpp"

#define TEMPO_DANO 2.f
#define TEMPO_DESCANSO 1.f

namespace Entidades {
namespace Personagens {
class Personagem : public Entidade {
protected:
  bool onFloor;
  bool ataque;
  bool danar;
  float jumpTime;
  float danoTime;
  int num_vidas;

public:
  Personagem(const sf::Vector2f pos, const sf::Vector2f size,
             const Entidades::ID id);
  ~Personagem();
  void move();
  virtual void inicializa() = 0;
  virtual void animacao() = 0;
  virtual void operator--(const int dano) = 0;
  virtual void tratarColisao(Entidade *entidade, const sf::Vector2f mtv) = 0;
  virtual void atualizaBarraDeVida() = 0;
  virtual void verificaSolo(const sf::Vector2f mtv);
  void setOnFloor(const bool floor);
  void setAtaque(const bool ataque);
  const bool getAtacando();
  const float getJumpTime() const;
  const int getNum_vidas() const;
  virtual void salvar(std::ostringstream *entrada) = 0;
  virtual void executar() = 0;
  virtual void update() = 0;
  virtual void atacar() = 0;
};
} // namespace Personagens
} // namespace Entidades
