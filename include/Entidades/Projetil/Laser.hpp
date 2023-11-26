#pragma once

#include "Entidades/Personagens/Inimigo/Viajante.hpp"

#define TAM_PROJETIL 10.0f

namespace Entidades {
class Laser : public Entidade {
private:
  static int dano;
  bool Ativo;
  //Personagens::Viajante *pInim;
  sf::Vector2f vel;
  bool onFloor;

public:
  Laser(const sf::Vector2f pos, const sf::Vector2f vel, const Entidades::ID id);
  Laser(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Laser();
  void tratarColisao(Entidades::Entidade *entidade, const sf::Vector2f mtv);
  void verificaSolo(const sf::Vector2f mtv);
  static void setDano(const int dano);
  const bool getAtivo() const;
  void move();
  void draw();
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Entidades