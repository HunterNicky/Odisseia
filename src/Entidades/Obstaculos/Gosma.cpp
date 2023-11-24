#include "..\..\..\include\Entidades\Obstaculos\Gosma.hpp"
#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"

namespace Entidades {
namespace Obstaculos {
float Gosma::slow = 0.01;

Gosma::Gosma(const sf::Vector2f pos, const sf::Vector2f size,
             const Entidades::ID id)
    : Obstaculo(pos, size, id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_GOSMA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Green);
  contexto.setStrategy(&bloco, 0.1f);
}
Gosma::Gosma(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_GOSMA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Green);
  contexto.setStrategy(&bloco, 0.1f);
}
Gosma::~Gosma() {}

void Gosma::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

void Gosma::atrasar(Entidade *entidade) {
  sf::Vector2f forca = entidade->getForca() * slow;
  sf::Vector2f acc;
  acc.x = forca.x / entidade->getAcc().x;
  acc.y = forca.y / entidade->getAcc().y;
  entidade->setForca(forca);
}

void Gosma::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade) {
    if (entidade->getId() == Entidades::ID::jogador) {
      atrasar(entidade);
    }
  }
}

void Gosma::executar() { animacao(); }
void Gosma::update() { executar(); }

void Gosma::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 7 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "],  \"Tamanho\": [" << this->getSize().x << " , "
             << this->getSize().y << "] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades