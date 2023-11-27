#pragma once

#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Estados\MaquinaDeEstado.hpp"
#include "Menu/MenuGameOver.hpp"
#include "Menu/MenuPausa.hpp"
#include "Observer.hpp"

namespace Fases {
class Fase;

}
namespace Entidades {
namespace Personagens {
class Jogador;
}
} // namespace Entidades

namespace Observadores {
class ControleJogador : public Observer {
private:
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  Entidades::Personagens::Jogador *pJogador;
   Entidades::Personagens::Jogador *pJogador2;
  Fases::Fase *pFase;
  std::string pular, esquerda, direita, correr, atacar;
  std::string fechar;

public:
  ControleJogador(Entidades::Personagens::Jogador *pJogador,
                  Fases::Fase *pFase);
  ControleJogador(Entidades::Personagens::Jogador *pJogador, Entidades::Personagens::Jogador* pJogador2, Fases::Fase *pFase);
  ~ControleJogador();
  void setJogador(Entidades::Personagens::Jogador *pJogador);
  void setJogador2(Entidades::Personagens::Jogador *pJogador2);
  void jogadorNeutralizado();
  void notifyPressed(const sf::Keyboard::Key key);
  void notifyReleased(const sf::Keyboard::Key key);
};
} // namespace Observadores