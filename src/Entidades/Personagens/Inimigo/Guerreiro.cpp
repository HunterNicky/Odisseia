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
      atacando(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ATAQUE, 8, sf::Vector2f(3, 3)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ANDAR,
            CAMINHO_GUERREIRO_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  inicializa();
  if ((raivosidade >= 0) && (raivosidade < 3)) { // 30% chance de ser raivoso
    dano = 20;
  } else {
    dano = 10;
  }
}
Guerreiro::Guerreiro(nlohmann::json atributos, const int pos,
                     const Entidades::ID id,
                     Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]),
              sf::Vector2f(TAM_INIMIGO_FACIL_X, TAM_INIMIGO_FACIL_Y), id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ATAQUE, 8, sf::Vector2f(3, 3)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_ANDAR,
            CAMINHO_GUERREIRO_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_GUERREIRO_PARADO,
             10, sf::Vector2f(3, 3)),
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
    if (std::abs(vel.x) > 0.3f) {
      contextoAnimacao.setStrategy(&andar, 0.1f);
    } else {
      contextoAnimacao.setStrategy(&parado, 0.5f);
    }
  }
  if(ataque){
    contextoAnimacao.setStrategy(&atacando, 0.1f);
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}
void Guerreiro::operator--(const int dano) { 
  danoTime = gFisico->getDeltaTime();
  tomarDano = true;
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
  if((gFisico->getDeltaTime() - danoTime) > 5.f){
    tomarDano = false;
  }
 
  if(ataque && (!tomarDano) && (this->getPos().x - entidade->getPos().x) <= raio){
    Entidades::Personagens::Personagem *pPers =
        static_cast<Entidades::Personagens::Personagem *>(entidade);
    pPers->operator--(20);
    std::cout << "estive aq" << std::endl;
  }
}

void Guerreiro::tratarColisao(Entidade *entidade) {
  if (entidade->getId() == Entidades::ID::jogador) {
    danificar(entidade);
    ataque = true;
  }
}

void Guerreiro::executar() { move(); }

void Guerreiro::update() {
  executar();
  animacao();
}

void Guerreiro::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 2 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
}

void Guerreiro::atacar(){

}

} // namespace Personagens
} // namespace Entidades