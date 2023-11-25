#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoParado.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Projetil/Laser.hpp"
#include "Fases/Fase.hpp"

namespace Entidades {
namespace Personagens {
void Viajante::inicializa() {
  vel = sf::Vector2f(0.0f, 0.0f);
  // body->setFillColor(sf::Color{245,222,179, 255});
  srand(time(NULL));
  nivel_maldade = (int)rand() % 2;
  num_vidas = 100;
}
Viajante::Viajante(const sf::Vector2f pos, const sf::Vector2f size,
                   const Entidades::ID id,
                   Entidades::Personagens::Jogador *pJog,
                   Entidades::Laser *proj)
    : Inimigo(pos, size, id, pJog), pProj(proj),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_VIAJANTE_PROJETIL, 10, sf::Vector2f(3, 3)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_ANDAR,
            CAMINHO_VIAJANTE_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  inicializa();
  danoTime = 0;
  recoveryTime = 0;
}

Viajante::Viajante(nlohmann::json atributos, const int pos,
                   const Entidades::ID id,
                   Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]),
              sf::Vector2f(TAM_INIMIGO_MED_X, TAM_INIMIGO_MED_Y), id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_VIAJANTE_PROJETIL, 10, sf::Vector2f(3, 3)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_ANDAR,
            CAMINHO_VIAJANTE_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  this->num_vidas = atributos[pos]["Vida"][0];
  // body->setFillColor(sf::Color{245,222,179, 0});
}

Viajante::~Viajante() {}

void Viajante::animacao() {
  if (onFloor) {
    if (std::abs(vel.x) > 0.3f) {
      contextoAnimacao.setStrategy(&andar, 0.5f);
    } else {
      contextoAnimacao.setStrategy(&parado, 0.5f);
    }
    if(ataque){
      contextoAnimacao.setStrategy(&atacando, 0.1f);
    }
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}
void Viajante::operator--(const int dano) { 
  
  num_vidas -= dano; 
  }

void Viajante::movimentoAleatorio() {
  moveAleatorio = rand() % 2;
  if (moveAleatorio == 0) {
    forca.x = 3000.0f;
  } else {
    forca.x = -3000.0f;
  }
}

void Viajante::atirarProjetil(sf::Vector2f pos, const bool direita) {
  sf::Vector2f newPosition;
  if (direita) {
    newPosition = sf::Vector2f(pos.x + 25.f, pos.y-25.f);
    pProj->setPos(newPosition);
    pProj->setVel(sf::Vector2f(100.f, -1.f));
  } else {
    newPosition = sf::Vector2f(pos.x - 25.f, pos.y-25.f);
    pProj->setPos(newPosition);
    pProj->setVel(sf::Vector2f(-100.f, -1.f));
  }
}

void Viajante::setProj(Entidades::Laser *pProj) { this->pProj = pProj; }

const bool Viajante::getDirecaoProj() { return direita; }

void Viajante::move() {
  sf::Vector2f posJogador = pJogador->getBody()->getPosition();
  sf::Vector2f posInimigo = getBody()->getPosition();

  if ((fabs(posJogador.x - posInimigo.x) <= RANGE*2) &&
      (fabs(posJogador.y - posInimigo.y <= RANGE))) {
    forca.x = 0.0f;
    if (posJogador.x > posInimigo.x) {
      direita = true;
    } else {
      direita = false;
    }
    forca.x = -100.0f;
    atirarProjetil(posInimigo, direita);
    ataque = true;
  } else {
    movimentoAleatorio();
    ataque = false;
  }
  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}

void Viajante::atualizaBarraDeVida() {
  sf::Vector2f posBarraVida(sf::Vector2f(
      pos.x + getSize().x / 2.0f - body->getSize().x - 20.f, pos.y - 50.0f));
  barraVida->setPosition(posBarraVida);
  barraVida->setSize(sf::Vector2f((getNum_vidas() / 100.0f) * 60.f, 6.f));
  pGrafico->draw(dynamic_cast<sf::Drawable *>(barraVida));
}

void Viajante::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade->getId() == Entidades::ID::Plataforma) {
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
  }
}

void Viajante::executar() { move(); }

void Viajante::atacar() {
}

void Viajante::update() {
  recoveryTime +=gFisico->getDeltaTime();
  danoTime += gFisico->getDeltaTime();

 if(recoveryTime > TEMPO_DESCANSO) {
    recoveryTime = 0;
    tomouDano = false;
  }
  if(danoTime > TEMPO_DANO) { 
    danoTime = 0;
    danar = true;
    ataque = true;
  }

  executar();
  animacao();
}
void Viajante::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 3 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
}
} // namespace Personagens
} // namespace Entidades