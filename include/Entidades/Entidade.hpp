#pragma once

#include "Ente.hpp"
#include "Fases/json.hpp"
#include "Gerenciadores/Colisao/ConcreteGerenciadorColisao.hpp"
#include <fstream>
#include <iostream>
#include <sstream>


namespace Gerenciadores {
namespace Colisao {
class ConcreteGerenciadorColisao;
class CalculadorFisico;
} // namespace Colisao
} // namespace Gerenciadores

namespace Entidades {
enum class ID {
  empty = 0,
  jogador,
  Guerreiro,
  Viajante,
  Samurai,
  Plataforma,
  Caixa,
  Gosma,
  Lava,
  Laser
};

class Entidade : public Ente {
protected:
  int id;
  sf::RectangleShape *body;
  static Gerenciadores::Colisao::ConcreteGerenciadorColisao *gColisao;
  static Gerenciadores::Colisao::CalculadorFisico *gFisico;
  const Entidades::ID ID;
  bool entidadeEstatica;
  sf::Vector2f vel;
  sf::Vector2f acc;
  sf::Vector2f forca;
  sf::Vector2f prevPos;
  float massa;

public:
  Entidade(const sf::Vector2f pos, const sf::Vector2f size,
           const Entidades::ID id);
  virtual ~Entidade();
  const Entidades::ID getId() const;
  void setBody(sf::RectangleShape *body);
  void setConcreteGerenciadorColisao(
      Gerenciadores::Colisao::ConcreteGerenciadorColisao *gColisao);
  void setVel(const sf::Vector2f vel);
  void setAcc(const sf::Vector2f acc);
  void setMassa(const float massa);
  void setPrevPos(const sf::Vector2f prevPos);
  const bool getEstatico();
  const sf::Vector2f getVel() const;
  const sf::Vector2f getAcc() const;
  const sf::Vector2f getForca() const;
  const sf::Vector2f getPrevPos() const;
  const float getMass() const;
  sf::RectangleShape *getBody();
  virtual void executar() = 0;
  virtual void update() = 0;
  virtual void tratarColisao(Entidade *entidade, const sf::Vector2f mtv) = 0;
  virtual void verificaSolo(const sf::Vector2f mtv) = 0;
  virtual void salvar(std::ostringstream *entrada) = 0;
  virtual void draw();
};
} // namespace Entidades