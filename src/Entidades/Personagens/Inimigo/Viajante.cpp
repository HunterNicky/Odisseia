#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Fases/Fase.hpp"

namespace Entidades {
namespace Personagens {
void Viajante::inicializa() {
  srand(time(NULL));
  vel = sf::Vector2f(0.0f, 0.0f);
  nivel_maldade = 2;
  num_vidas = 100;
  dano = 25;
  raio = RAIO;
  danoTime = 0;
  Entidades::Laser::setDano(dano * nivel_maldade); // inicializa dano projétil
}
Viajante::Viajante(const sf::Vector2f pos, const sf::Vector2f size,
                   const Entidades::ID id,
                   Entidades::Personagens::Jogador *pJog)
    : Inimigo(pos, size, id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_VIAJANTE_PROJETIL, 10, sf::Vector2f(3 * 2.2, 3 * 0.937)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_ANDAR,
            CAMINHO_VIAJANTE_ANDAR, 8, 8, sf::Vector2f(3 * 1.05, 3 * 0.9),
            sf::Vector2f(3 * 1.05, 3 * 0.9)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_PARADO,
             10, sf::Vector2f(3 * 0.95, 3 * 0.937)),
      contextoAnimacao() {
  inicializa();
}

Viajante::Viajante(nlohmann::json atributos, const int pos,
                   const Entidades::ID id,
                   Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]),
              sf::Vector2f(TAM_INIMIGO_MED_X, TAM_INIMIGO_MED_Y), id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_VIAJANTE_PROJETIL, 10, sf::Vector2f(3 * 2.2, 3 * 0.937)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_ANDAR,
            CAMINHO_VIAJANTE_ANDAR, 8, 8, sf::Vector2f(3 * 1.05, 3 * 0.9),
            sf::Vector2f(3 * 1.05, 3 * 0.9)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_VIAJANTE_PARADO,
             10, sf::Vector2f(3 * 0.95, 3 * 0.937)),
      contextoAnimacao() {
  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  this->num_vidas = atributos[pos]["Vida"][0];
  this->danoTime = atributos[pos]["DanoTime"][0];
  nivel_maldade = 2;
  dano = 25;
  raio = RAIO;
  Entidades::Laser::setDano(dano * nivel_maldade); // inicializa dano projétil
}

Viajante::~Viajante() {}

void Viajante::animacao() {
  if (onFloor) {
    if (std::abs(vel.x) > 0.1f) {
      contextoAnimacao.setStrategy(&andar, 0.1f);
    } else {
      contextoAnimacao.setStrategy(&parado, 1.0f);
    }
    if (ataque) {
      contextoAnimacao.setStrategy(&atacando, 0.1f);
    }
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}
void Viajante::operator--(const int dano) { num_vidas -= dano; }

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

  if (danar) {
    if (direita) {
      newPosition = sf::Vector2f(pos.x + 25.f, pos.y - 25.f);
      pFase->newProjetil(newPosition, sf::Vector2f(-VEL_PROJ_X, VEL_PROJ_Y));
    } else {
      newPosition = sf::Vector2f(pos.x - 25.f, pos.y - 25.f);
      pFase->newProjetil(newPosition, sf::Vector2f(VEL_PROJ_X, VEL_PROJ_Y));
    }
    danar = false;
  }
}

void Viajante::setFase(Fases::Fase *pFase) { this->pFase = pFase; }

void Viajante::move() {
  sf::Vector2f posJogador = pJogador->getBody()->getPosition();
  sf::Vector2f posInimigo = getBody()->getPosition();

  if (((fabs(posJogador.x - posInimigo.x) <= raio * 2) &&
       (fabs(posJogador.y - posInimigo.y <= raio))) &&
      danar) {
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

void Viajante::atacar() {}

void Viajante::update() {
  danoTime += gFisico->getDeltaTime();

  if (danoTime > TEMPO_DANO) {
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
             << "], \"Vida\": [" << this->getNum_vidas() << "], \"DanoTime\": [" << danoTime << "] }" << std::endl;
}
} // namespace Personagens
} // namespace Entidades