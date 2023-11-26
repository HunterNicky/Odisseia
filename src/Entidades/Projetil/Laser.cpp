#include "Entidades/Projetil/Laser.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"

namespace Entidades {
// Dano do projetil
int Laser::dano(0);

void Laser::setDano(const int dano){
  Laser::dano = dano;
}

Laser::Laser(const sf::Vector2f pos, const sf::Vector2f vel,
             const Entidades::ID id)
    : Entidade(pos, sf::Vector2f(TAM_PROJETIL, TAM_PROJETIL / 2), id) {
  body->setFillColor(sf::Color::Red);
  Ativo = true;
  this->vel = vel;
}

Laser::Laser(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Entidade(sf::Vector2f(atributos[pos]["Posicao"][0],
                            atributos[pos]["Posicao"][1]),
               sf::Vector2f(TAM_PROJETIL, TAM_PROJETIL/2), id) {
  body->setFillColor(sf::Color::Red);
  this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0],
                            atributos[pos]["Velocidade"][1]));
  //this->Ativo = atributos[pos]["Ativo"][0] == 1 ? true : false;
}

Laser::~Laser() {}

void Laser::tratarColisao(Entidades::Entidade *entidade,
                          const sf::Vector2f mtv) {
  if (entidade->getId() == Entidades::ID::jogador) {
    std::cout << "Laser colidiu com jogador!" << std::endl;
    Entidades::Personagens::Personagem *pPers =
        static_cast<Entidades::Personagens::Personagem *>(entidade);
    pPers->operator--(dano);
    Ativo = false;
  } else if (entidade->getId() == Entidades::ID::Plataforma) {
    Ativo = false;
  }
}

void Laser::verificaSolo(const sf::Vector2f mtv) {
  if (mtv.y < 0.f) {
    onFloor = true;
  } else {
    onFloor = false;
  }
}

const bool Laser::getAtivo() const { return Ativo; }

void Laser::move() {
   if (vel.x < 0.f) {
     setVel(sf::Vector2f(-100.f, -20.f));
   } else {
     setVel(sf::Vector2f(100.f, -20.f));
   }
  body->move(vel);
}

void Laser::draw() {
  if(Ativo){
    pGrafico->draw(body);
  }
}

void Laser::executar() {
  move();
  Entidade::body->setPosition(pos);
  gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}

void Laser::update() { executar(); }
void Laser::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 9 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y
             << "] }" << std::endl; //, \"Ativo\": ["<< Ativo <<"]
}
} // namespace Entidades