#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include <iostream>
#include <ostream>

namespace Entidades {
namespace Personagens {
void Jogador::inicializa() {
  vel = sf::Vector2f(0.0f, 0.0f);
  num_vidas = 1000;
  contextoAnimacao.setStrategy(
      static_cast<Animacao::AnimacaoStrategy *>(&parado), 0.1f);
  estamina = 1.f;
}

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f size,
                 const Entidades::ID id)
    : Personagem(pos, size, id),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_ANDAR_JOG,
            CAMINHO_CORRER_JOG, 8, 8, sf::Vector2f(3 * 1.35, 3 * 0.96),
            sf::Vector2f(3 * 1.4, 3 * 0.90)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_PARADO_JOG, 10,
             sf::Vector2f(3, 3)),
      pulando(static_cast<Entidades::Entidade *>(this), CAMINHO_PULAR_JOG,
              CAMINHO_SPIN_JOG, 3, 6, sf::Vector2f(3 * 1.10, 3 * 1.09),
              sf::Vector2f(3 * 1.4, 3 * 1.09)),
      atacando(static_cast<Entidades::Entidade *>(this), CAMINHO_ATACAR_JOG, 7,
               sf::Vector2f(3 * 3.7, 3 * 0.93)),
      contextoAnimacao() {
  inicializa();
}

Jogador::Jogador(nlohmann::json atributos, const int pos,
                 const Entidades::ID id)
    : Personagem(sf::Vector2f(atributos[pos]["Posicao"][0],
                              atributos[pos]["Posicao"][1]),
                 sf::Vector2f(TAM_X_JOGADOR, TAM_Y_JOGADOR), id),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_ANDAR_JOG,
            CAMINHO_CORRER_JOG, 8, 8, sf::Vector2f(3 * 1.35, 3 * 0.96),
            sf::Vector2f(3 * 1.4, 3 * 0.90)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_PARADO_JOG, 10,
             sf::Vector2f(3, 3)),
      pulando(static_cast<Entidades::Entidade *>(this), CAMINHO_PULAR_JOG,
              CAMINHO_SPIN_JOG, 3, 6, sf::Vector2f(3 * 1.10, 3 * 1.09),
              sf::Vector2f(3 * 1.4, 3 * 1.09)),
      atacando(static_cast<Entidades::Entidade *>(this), CAMINHO_ATACAR_JOG, 7,
               sf::Vector2f(3 * 3.7, 3 * 0.93)),
      contextoAnimacao() {

  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  this->num_vidas = atributos[pos]["Vida"][0];
}
Jogador::~Jogador() {}

void Jogador::operator--(const int dano) {
  std::cout << num_vidas << std::endl;
  this->num_vidas -= dano;
}

void Jogador::animacao() {
  if (ataque) {
    contextoAnimacao.setStrategy(&atacando, 0.1f);
  } else if (onFloor) {
    if (std::abs(vel.x) > 0.3f) {
      contextoAnimacao.setStrategy(&andar, 0.1f);
    } else {
      contextoAnimacao.setStrategy(&parado, 0.5f);
    }
  } else if (vel.y < -0.5f) {
    contextoAnimacao.setStrategy(&pulando, 0.1f);
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}

const bool Jogador::getProximaFase() { return proximaFase; }

void Jogador::move() {
  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}

void Jogador::direcionar(bool side) {
  if (side) {
    forca.x = 5000.f;
  } else {
    forca.x = -5000.f;
  }
  if (!onFloor)
    forca.y = 0;
}

void Jogador::correr() {
  if (estamina < 0.1f) {
    estamina = 0.1f;
    if (forca.x > 0.f) {
      direcionar(true);
    } else {
      direcionar(false);
    }
  } else {
    estamina -= gFisico->getDeltaTime();
    if (forca.x != 0.f) {
      if (estamina > 0.4f)
        forca.x *= 1.01f;
      else
        forca.x /= 1.01f;
    }
  }
}

void Jogador::atacar() { ataque = true; }

void Jogador::pular() {
  jumpTime += gFisico->getDeltaTime();
  if (onFloor && jumpTime < gFisico->getDeltaTime() * 3) {
    forca.y = -80000.f;
  } else {
    forca.y = 0;
  }
  if (jumpTime > gFisico->getDeltaTime() * 6) {
    jumpTime = gFisico->getDeltaTime() * 6;
  }
}

void Jogador::danificarInimigo(Entidade *pInimigo) {
  float range = 100.f;

  if((gFisico->getDeltaTime() - danoTime ) > 5.f){
    tomarDano = false;
  }

  if((ataque && (!tomarDano)) && (this->getPos().x - pInimigo->getPos().x) <= range){
    Entidades::Personagens::Personagem *pPers =
        static_cast<Entidades::Personagens::Personagem *>(pInimigo);
    pPers->operator--(20);
    std::cout << "estive aq" << std::endl;
  }
}

void Jogador::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  switch (entidade->getId()) {
  case (ID::Guerreiro):
    danificarInimigo(entidade);
    break;
  case (ID::Viajante):
    //neutralizarInimigo(entidade);
    break;
  case (ID::Samurai):
    //neutralizarInimigo(entidade);
    break;
  case (ID::Plataforma):
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
    break;
  case (ID::Caixa):
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
break;
  case (ID::Gosma):
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    break;
  case (ID::Lava):
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    break;
  default:
    break;
  }
}

const float Jogador::getEstamina() const { return estamina; }

void Jogador::parar() { forca.x = 0; }

void Jogador::executar() {
  animacao();
  move();
}

void Jogador::update() {
  if (estamina < 1.f)
    estamina += estamina * 0.0001f + 0.001f;
  executar();
}

void Jogador::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 1 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
}
} // namespace Personagens
} // namespace Entidades