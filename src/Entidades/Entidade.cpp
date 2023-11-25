#include "..\..\include\Entidades\Entidade.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorDeColisao.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"

namespace Entidades {
Gerenciadores::GerenciadorFisico *Entidade::gFisico =
    Gerenciadores::GerenciadorFisico::getInstance();
Gerenciadores::GerenciadorDeColisao *Entidade::gColisao =
    Gerenciadores::GerenciadorDeColisao::getInstance();

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f size,
                   const Entidades::ID id)
    : Ente(pos, size), body(new sf::RectangleShape(size)), ID(id), prevPos(pos),
      massa(20) {
  if (id == Entidades::ID::Gosma || id == Entidades::ID::Lava ||
      id == Entidades::ID::Plataforma) {
    entidadeEstatica = true;
  } else {
    entidadeEstatica = false;
  }
  body->setPosition(pos);
  body->setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
}

Entidade::~Entidade() { delete (body); }

const ID Entidade::getId() const { return ID; }

void Entidade::setBody(sf::RectangleShape *body) { this->body = body; }

sf::RectangleShape *Entidade::getBody() { return body; }

void Entidade::draw() { pGrafico->draw(body); }

void Entidade::setGerenciadorDeColisao(
    Gerenciadores::GerenciadorDeColisao *gColisao) {
  this->gColisao = gColisao;
}

const bool Entidade::getEstatico() { return entidadeEstatica; }

void Entidade::setVel(const sf::Vector2f vel) { this->vel = vel; }

void Entidade::setAcc(const sf::Vector2f acc) { this->acc = acc; }

void Entidade::setForca(const sf::Vector2f forca) { this->forca = forca; }

void Entidade::setMassa(const float massa) { this->massa = massa; }

const sf::Vector2f Entidade::getVel() const { return vel; }

const sf::Vector2f Entidade::getAcc() const { return acc; }

const sf::Vector2f Entidade::getForca() const { return forca; }

const float Entidade::getMass() const { return massa; }

void Entidade::setPrevPos(const sf::Vector2f prevPos) {
  this->prevPos = prevPos;
}

const sf::Vector2f Entidade::getPrevPos() const { return prevPos; }
} // namespace Entidades