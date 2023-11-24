#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Samurai.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoParado.hpp"

#include <sstream>
#include <stdlib.h>
#include <time.h>

namespace Entidades {
namespace Personagens {
void Samurai::inicializa() {
  vel = sf::Vector2f(0.01f, 0.01f);
  num_vidas = 1000;
  body->setFillColor(sf::Color::Yellow);
}

Samurai::Samurai(const sf::Vector2f pos, const sf::Vector2f size,
                 const Entidades::ID id, Entidades::Personagens::Jogador *pJog)
    : Inimigo(pos, size, id, pJog),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_ANDAR,
            CAMINHO_SAMURAI_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  inicializa();
}

Samurai::Samurai(nlohmann::json atributos, const int pos,
                 const Entidades::ID id, Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]),
              sf::Vector2f(TAM_INIMIGO_DIF_X, TAM_INIMIGO_DIF_Y), id, pJog),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_ANDAR,
            CAMINHO_SAMURAI_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  this->num_vidas = atributos[pos]["Vida"][0];
}

Samurai::~Samurai() {}
void Samurai::animacao() {
  if (onFloor) {
    if (std::abs(vel.x) > 0.3f) {
      contextoAnimacao.setStrategy(&andar, 0.1f);
    } else {
      contextoAnimacao.setStrategy(&parado, 0.5f);
    }
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}

void Samurai::operator--(const int dano) { num_vidas -= dano; }
void Samurai::movimentoAleatorio() {
  srand(time(NULL));
  moveAleatorio = rand() % 2;

  if (moveAleatorio == 0) {
    forca.x = 3000;
  } else {
    forca.x = -3000;
  }
}
void Samurai::move() {
  sf::Vector2f posicaoJog = pJogador->getBody()->getPosition();
  sf::Vector2f posicaoSamurai = getBody()->getPosition();

  if (((fabs(posicaoJog.x - posicaoSamurai.x) <= R)) &&
      (fabs(posicaoJog.y - posicaoSamurai.y) <= R)) {
    // strategy atacar
  } else {
    movimentoAleatorio();
  }

  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}

void Samurai::danificar(Entidade *entidade) {
  Entidades::Personagens::Personagem *pPers =
      static_cast<Entidades::Personagens::Personagem *>(entidade);
  pPers->operator--(200);
}

void Samurai::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade->getId() == Entidades::ID::Plataforma){
    entidade->tratarColisao(static_cast<Entidades::Entidade*>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
  }else if (entidade->getId() == Entidades::ID::jogador) {
    danificar(entidade);
  }
}

void Samurai::atacar() {}

void Samurai::executar() { move(); }

void Samurai::update() {
  executar();
  animacao();
}

void Samurai::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 4 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
}
} // namespace Personagens
} // namespace Entidades