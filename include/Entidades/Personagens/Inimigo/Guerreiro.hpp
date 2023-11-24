#pragma once

#include "Inimigo.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM_INIMIGO_FACIL_X 20.f
#define TAM_INIMIGO_FACIL_Y 32.0f

#define CAMINHO_GUERREIRO_ANDAR "data\\Sprites\\warrior\\warriorwalk.png"
#define CAMINHO_GUERREIRO_PARADO "data\\Sprites\\warrior\\warrioridle.png"
#define CAMINHO_GUERREIRO_ATAQUE "data\\Sprites\\warrior\\warriorattack.png"

namespace Entidades {
namespace Personagens {
class Guerreiro : public Inimigo {
private:
  int raivosidade;

  Animacao::AnimacaoAndar andar;
  Animacao::AnimacaoParado parado;
  Animacao::AnimacaoContext contextoAnimacao;
  void inicializa();

public:
  Guerreiro(const sf::Vector2f pos, const sf::Vector2f size,
            const Entidades::ID id, Entidades::Personagens::Jogador *pJog);
  Guerreiro(nlohmann::json atributos, const int pos, const Entidades::ID id,
            Entidades::Personagens::Jogador *pJog);
  ~Guerreiro();
  void animacao();
  void operator--(const int dano);
  void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
  void movimentoAleatorio();
  void move();
  void danificar(Entidade *entidade);
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void atacar();
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Personagens
} // namespace Entidades