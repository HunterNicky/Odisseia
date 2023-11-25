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
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_LAVA,8,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Red);
  contexto.setStrategy(&bloco, 1.f);
  danoTime = 0;
}

Lava::Lava(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_LAVA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Red);
  contexto.setStrategy(&bloco, 0.1);
  danoTime = 0;
}
Lava::~Lava() {}

void Lava::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

void Lava::queimar(Entidade *entidade) {

  if(danoso){
    Entidades::Personagens::Personagem *pPers =
        static_cast<Entidades::Personagens::Personagem *>(entidade);

    pPers->operator--(queimadura);
    danoso = false;
  }
}

void Lava::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade) {
    if (entidade->getId() == Entidades::ID::jogador) {
      queimar(entidade);
    }
    if (!entidade->getEstatico()) {
      entidade->setPos(sf::Vector2f(entidade->getPos().x + mtv.x,
                                    entidade->getPos().y + mtv.y));
      entidade->setPrevPos(sf::Vector2f(entidade->getPrevPos().x + mtv.x * 0.9f,
                                      entidade->getPrevPos().y + mtv.y * 0.9f));
    }
  }
}

void Lava::executar() { animacao(); }

void Lava::update() { 
  danoTime += gFisico->getDeltaTime();

  if(danoTime > 2.0f){
    danoso = true;
    danoTime = 0.0f;
  }
  executar(); 
  }

void Lava::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 8 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "],  \"Tamanho\": [" << this->getSize().x << " , "
             << this->getSize().y << "] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades