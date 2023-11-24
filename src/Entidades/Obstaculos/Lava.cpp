#include "..\..\..\include\Entidades\Obstaculos\Lava.hpp"
#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Lava.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <cstdlib>
#include <iostream>

namespace Entidades {
namespace Obstaculos {
unsigned int Lava::queimadura = 50;

Lava::Lava(const sf::Vector2f pos, const sf::Vector2f size,
           const Entidades::ID id)
    : Obstaculo(pos, size, id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_LAVA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Red);
  contexto.setStrategy(&bloco, 0.1);
}
Lava::~Lava() {}
void Lava::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }
void Lava::queimar(Entidade *entidade) {
  Entidades::Personagens::Personagem *pPers =
      static_cast<Entidades::Personagens::Personagem *>(entidade);
  pPers->operator--(queimadura);
}

void Lava::tratarColisao(Entidade *entidade) {
  if (entidade) {
    if (entidade->getId() == Entidades::ID::jogador) {
      queimar(entidade);
    }
  }
}

void Lava::executar() { animacao(); }
void Lava::update() { executar(); }

void Lava::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 6 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades