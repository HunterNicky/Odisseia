#pragma once

// #include "Entidades/Laser/Laser.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoAtaque.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoParado.hpp"
#include "Inimigo.hpp"
#include <math.h>

#define TAM_INIMIGO_MED_X 20.0f
#define TAM_INIMIGO_MED_Y 32.0f

#define CAMINHO_VIAJANTE_ANDAR "data\\Sprites\\travel\\travelwalk.png"
#define CAMINHO_VIAJANTE_PARADO "data\\Sprites\\travel\\travelidle.png"
#define CAMINHO_VIAJANTE_PROJETIL "data\\Sprites\\travel\\travelshoot.png"

namespace Fases {
class Fase;
}

#define RANGE 200.0f
namespace Entidades {
class Laser;
namespace Personagens {
class Viajante : public Inimigo {
private:
  Entidades::Laser *pProj;
  bool ProjAtivo;
  bool direita;
  Animacao::AnimacaoAndar andar;
  Animacao::AnimacaoParado parado;
  Animacao::AnimacaoAtaque atacando;
  Animacao::AnimacaoContext contextoAnimacao;
  void inicializa();

public:
  Viajante(const sf::Vector2f pos, const sf::Vector2f size,
           const Entidades::ID id, Entidades::Personagens::Jogador *pJog,
           Entidades::Laser *proj);
  Viajante(nlohmann::json atributos, const int pos, const Entidades::ID id,
           Entidades::Personagens::Jogador *pJog);
  ~Viajante();
  void animacao();
  void operator--(const int dano);
  void movimentoAleatorio();
  void atirarProjetil(sf::Vector2f pos, const bool direita);
  void deletarProjetil();
  void setProj(Entidades::Laser *pProj);
  const bool getProjAtivo();
  const bool getDirecaoProj();
  void move();
  void atacar();
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Personagens
} // namespace Entidades