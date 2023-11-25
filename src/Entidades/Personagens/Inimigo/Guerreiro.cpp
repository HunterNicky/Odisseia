#include "Entidades/Personagens/Inimigo/Guerreiro.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoAtaque.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoParado.hpp"
#include "Entidades/Entidade.hpp"
#include <exception>

namespace Entidades {
namespace Personagens {
void Guerreiro::inicializa() {
  vel = sf::Vector2f(0.1f, 0.1f);
  // body->setFillColor(sf::Color::Red);
  raio = RAIO;
  num_vidas = 100;
  srand(time(NULL));
  moveAleatorio = rand() % 4;
  raivosidade = rand() % 10;
}

Guerreiro::Guerreiro(const sf::Vector2f pos, const sf::Vector2f size,
                     const Entidades::ID id,
                     Entidades::Personagens::Jogador *pJog)
    : Inimigo(pos, size, id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_GUERREIRO_ATAQUE, 6, sf::Vector2f(3 * 2.95, 3 * 1.28)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ANDAR,
            CAMINHO_GUERREIRO_ANDAR, 8, 8, sf::Vector2f(3 * 1.05, 3 * 1.06),
            sf::Vector2f(3 * 1.05, 3 * 1.06)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_PARADO,
             10, sf::Vector2f(3 * 1.1, 3 * 1.09)),
      contextoAnimacao() {
  inicializa();
  if ((raivosidade >= 0) && (raivosidade < 3)) { // 30% chance de ser raivoso
    dano = 20;
  } else {
    dano = 10;
  }
  danoTime = 0;
  recoveryTime = 0;
}
Guerreiro::Guerreiro(nlohmann::json atributos, const int pos,
                     const Entidades::ID id,
                     Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]),
              sf::Vector2f(TAM_INIMIGO_FACIL_X, TAM_INIMIGO_FACIL_Y), id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this),
               CAMINHO_GUERREIRO_ATAQUE, 8, sf::Vector2f(3 * 2.95, 3 * 1.28)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ANDAR,
            CAMINHO_GUERREIRO_ANDAR, 8, 8, sf::Vector2f(3 * 1.05, 3 * 1.06),
            sf::Vector2f(3 * 1.05, 3 * 1.06)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_PARADO,
             10, sf::Vector2f(3 * 1.1, 3 * 1.09)),
      contextoAnimacao() {
  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  body->setFillColor(sf::Color::Red);
  this->num_vidas = atributos[pos]["Vida"][0];
  raio = RAIO;
  srand(time(NULL));
  this->raivosidade = rand() % 10;
  if ((raivosidade >= 0) && (raivosidade < 3)) { // 30% chance de ser raivoso
    dano = 20;
  } else {
    dano = 10;
  }
}
Guerreiro::~Guerreiro() {}

void Guerreiro::animacao() {
  if (onFloor) {
    if (std::abs(vel.x) > 0.1f) {
      contextoAnimacao.setStrategy(&andar, 0.1f);
    } else {
      contextoAnimacao.setStrategy(&parado, 1.f);
    }
  }
  if (ataque) {
    contextoAnimacao.setStrategy(&atacando, 0.3f);
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}
void Guerreiro::operator--(const int dano) { 
  recoveryTime = gFisico->getDeltaTime();
  tomouDano = true;
  num_vidas -= dano;
}

void Guerreiro::persegueJogador(sf::Vector2f posJogador,
                                sf::Vector2f posInimigo) {
  if (posJogador.x - posInimigo.x > 0.0f) {
    forca.x = 3000.f;
  } else {
    forca.x = -3000.f;
  }

  if (posJogador.y - posInimigo.y > 0.0f) {
    forca.y = 30000.f;
  } else {
    forca.y = -30000.f;
  }
}

void Guerreiro::movimentoAleatorio() {
  moveAleatorio = rand() % 4;
  if (moveAleatorio == 0) {
    forca.x = 3000.0f;
  } else if (moveAleatorio == 1) {
    forca.x = -3000.0f;
  } else if (moveAleatorio == 2) {
    forca.y = 3000.0f;
  } else {
    forca.y = -3000.0f;
  }
}

void Guerreiro::move() {
  sf::Vector2f posJogador = pJogador->getBody()->getPosition();
  sf::Vector2f posInimigo = body->getPosition();

  if ((fabs(posJogador.x - posInimigo.x) <= raio) &&
      (fabs(posJogador.y - posInimigo.y) <= raio)) {
    persegueJogador(posJogador, posInimigo);
  } else {
    movimentoAleatorio();
  }
  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}

void Guerreiro::danificar(Entidade *entidade) {
 
  if(danar && (this->getPos().x - entidade->getPos().x) <= raio){
      Entidades::Personagens::Personagem *pPers =
          static_cast<Entidades::Personagens::Personagem *>(entidade);
      pPers->operator--(dano);

      danar = false;   
  }
}

void Guerreiro::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade->getId() == Entidades::ID::Plataforma) {
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
  } else if (entidade->getId() == Entidades::ID::jogador) {
    danificar(entidade);
    ataque = true;
  }
}
void Guerreiro::atualizaBarraDeVida(){
  sf::Vector2f posBarraVida(sf::Vector2f(pos.x + getSize().x / 2.0f - body->getSize().x - 20.f, pos.y - 50.0f)); 
  barraVida->setPosition(posBarraVida);
  barraVida->setSize(sf::Vector2f((getNum_vidas() / 100.0f) * 60.f, 6.f));
  pGrafico->draw(dynamic_cast<sf::Drawable*>(barraVida));
}

void Guerreiro::executar() { move(); }

void Guerreiro::update() {
  recoveryTime +=gFisico->getDeltaTime();
  danoTime += gFisico->getDeltaTime();

  //Atualiza timers
  if(recoveryTime > TEMPO_DESCANSO) {
    recoveryTime = 0;
    tomouDano = false;
  }
  if(danoTime > TEMPO_DANO) { 
    danoTime = 0;
    danar = true;
  }
  executar();
  animacao();
}

void Guerreiro::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 2 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
}

void Guerreiro::atacar() {}

} // namespace Personagens
} // namespace Entidades