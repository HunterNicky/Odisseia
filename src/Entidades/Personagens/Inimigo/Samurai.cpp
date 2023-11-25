#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Samurai.hpp"
#include "Animacao/AnimacaoAndar.hpp"
#include "Animacao/AnimacaoAtaque.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Animacao/AnimacaoParado.hpp"
#include "Gerenciadores/QuadTree.hpp"

#include <sstream>
#include <stdlib.h>
#include <time.h>

namespace Entidades {
namespace Personagens {
void Samurai::inicializa() {
  vel = sf::Vector2f(0.01f, 0.01f);
  num_vidas = 100;
  body->setFillColor(sf::Color::Yellow);
}

Samurai::Samurai(const sf::Vector2f pos, const sf::Vector2f size,
                 const Entidades::ID id, Entidades::Personagens::Jogador *pJog)
    : Inimigo(pos, size, id, pJog),
      atacando(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_ATAQUE,
               8, sf::Vector2f(3.f, 3.f)),
      andar(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_ANDAR,
            CAMINHO_SAMURAI_ANDAR, 8, 8, sf::Vector2f(3, 3),
            sf::Vector2f(3, 3)),
      parado(static_cast<Entidades::Entidade *>(this), CAMINHO_SAMURAI_PARADO,
             10, sf::Vector2f(3, 3)),
      contextoAnimacao() {
  inicializa();
  danoTime = 0;
  recoveryTime = 0;
  tempoInvisivel = 0;
  tempoVisivel = 0;
}

Samurai::Samurai(nlohmann::json atributos, const int pos,
                 const Entidades::ID id, Entidades::Personagens::Jogador *pJog)
    : Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0],
                           atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_INIMIGO_DIF_X, TAM_INIMIGO_DIF_Y), id, pJog),
      atacando(static_cast<Entidades::Entidade*>(this),
                       CAMINHO_SAMURAI_ATAQUE, 8, sf::Vector2f(3.f, 3.f)),
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
  if(!invisibilidade) {
    body->setFillColor(sf::Color::Yellow);
    if (onFloor) {
      if (std::abs(vel.x) > 0.3f) {
        contextoAnimacao.setStrategy(&andar, 0.1f);
      } else {
        contextoAnimacao.setStrategy(&parado, 0.5f);
      }
    }
    if(ataque){
      contextoAnimacao.setStrategy(&atacando, 0.3f);
    }
  }else{
    this->body->setFillColor(sf::Color{0,0,0,0});
  }
  contextoAnimacao.updateStrategy(gFisico->getDeltaTime());
}

void Samurai::operator--(const int dano) { 
  if(!invisibilidade){
    std::cout << num_vidas << std::endl;
    num_vidas -= dano; 
  }
}

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
  if(danar){
    Entidades::Personagens::Personagem *pPers =
        static_cast<Entidades::Personagens::Personagem *>(entidade);
    pPers->operator--(50);
    danar = false;
    ataque = true;
  }
}
void Samurai::atualizaBarraDeVida(){
  if(!invisibilidade) {
    sf::Vector2f posBarraVida(sf::Vector2f(pos.x + getSize().x / 2.0f - body->getSize().x - 20.f, pos.y - 50.0f)); 
    barraVida->setPosition(posBarraVida);
    barraVida->setSize(sf::Vector2f((getNum_vidas() / 100.0f) * 60.f, 6.f));
    pGrafico->draw(dynamic_cast<sf::Drawable*>(barraVida));
  }
}

void Samurai::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade->getId() == Entidades::ID::Plataforma) {
    entidade->tratarColisao(static_cast<Entidades::Entidade *>(this), mtv);
    verificaSolo(mtv);
    pos.x -= vel.x * 0.01f;
  } else if (entidade->getId() == Entidades::ID::jogador) {
    danificar(entidade); 
  }
}

void Samurai::atacar() {}

void Samurai::executar() { move(); }

void Samurai::update() {
  recoveryTime +=gFisico->getDeltaTime();
  danoTime += gFisico->getDeltaTime();
  tempoInvisivel += gFisico->getDeltaTime();
  tempoVisivel += gFisico->getDeltaTime();

  if(danoTime > TEMPO_DANO) { 
    danoTime = 0;
    danar = true;
  }
  if(tempoInvisivel > 2.f){
    if(invisibilidade){
      tempoVisivel = 0;
    }
    invisibilidade = false; 
  }
  if (tempoVisivel > 2.f ){
    if(!invisibilidade){
      tempoInvisivel = 0;
    }
    invisibilidade = true;
  }
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