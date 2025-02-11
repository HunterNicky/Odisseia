#pragma once

#include "..\Jogador\Jogador.hpp"
#include "Gerenciadores/Colisao/CalculadorFisico.hpp"
#include "Lista/ListaDeEntidades.hpp"

#define RAIO 200.0f
namespace Entidades {
namespace Personagens {
class Inimigo : public Personagem {
protected:
  Entidades::Personagens::Jogador *pJogador;
  sf::RectangleShape* barraVida;
  int nivel_maldade;
  int moveAleatorio;
  float raio;
  int dano;

public:
  Inimigo(const sf::Vector2f pos, const sf::Vector2f size,
          const Entidades::ID id, Entidades::Personagens::Jogador *pJog);
  ~Inimigo();
  void inicializaVidaIni();
  virtual void atualizaBarraDeVida() = 0;
  virtual void inicializa() = 0;
  virtual void animacao() = 0;
  virtual void operator--(const int dano) = 0;
  virtual void movimentoAleatorio() = 0;
  virtual void move() = 0;
  virtual void tratarColisao(Entidade *entidade, const sf::Vector2f mtv) = 0;
  virtual void executar() = 0;
  virtual void update() = 0;
  virtual void salvar(std::ostringstream *entrada) = 0;
  virtual void atacar() = 0;
};
} // namespace Personagens
} // namespace Entidades