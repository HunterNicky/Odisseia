#pragma once

#include "..\Personagens\Personagem.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Fases/json.hpp"
#include "Obstaculo.hpp"
#define CAMINHO_BLOCO_GOSMA "data\\Sprites\\blocos\\gosma.png"
namespace Entidades {
namespace Obstaculos {
class Gosma : public Obstaculo {
private:
  static float slow;
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  Gosma(const sf::Vector2f pos, const sf::Vector2f size,
        const Entidades::ID id);
  Gosma(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Gosma();
  void animacao();
  void atrasar(Entidade *entidade);
  void tratarColisao(Entidade *entidade);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos
} // namespace Entidades