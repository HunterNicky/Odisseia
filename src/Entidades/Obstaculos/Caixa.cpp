#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades {
namespace Obstaculos {
Caixa::Caixa(const sf::Vector2f pos, const sf::Vector2f size,
             const Entidades::ID id, const std::string path)
    : Obstaculo(pos, size, id), PortalAtivo(false),
      bloco(static_cast<Entidades::Entidade *>(this), path, 5,
            sf::Vector2f(1, 1)),
      contexto() {
  contexto.setStrategy(&bloco, 1.f);
  this->body->setFillColor(sf::Color::White);
  idTextura = setarIdTextura(path);
  PortalAtivo = path == CAMINHO_BLOCO_PORTAL ? true : false;
  danoso = true;
  farpas = 1;
  danoTime = 0;
}

Caixa::Caixa(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this), 5, sf::Vector2f(1, 1)),
      contexto() {
  this->idTextura = atributos[pos]["Textura"][0];
  this->PortalAtivo = atributos[pos]["PortalAtivo"][0] == 1 ? true : false;
  this->danoTime = atributos[pos]["DanoTime"][0];
  this->danoso = atributos[pos]["Danoso"][0] == 1 ? true : false;

  bloco.setTexture(colocarTextura(idTextura));
  contexto.setStrategy(&bloco, 1.f);
  this->body->setFillColor(sf::Color::White);
  farpas = 1;
}
Caixa::~Caixa() {}

void Caixa::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

std::string Caixa::colocarTextura(int idText) {
  if (idText == 1) {
    return CAMINHO_BLOCO_CAIXA;
  } else if (idText == 2) {
    return CAMINHO_BLOCO_PORTAL;
  } else {
    return "";
  }
}

int Caixa::setarIdTextura(const std::string path) {
  if (path == CAMINHO_BLOCO_CAIXA) {
    return 1;
  } else if (path == CAMINHO_BLOCO_PORTAL) {
    return 2;
  } else {
    return -1;
  }
}

void Caixa::setPortalAtivo(const bool ativo) { PortalAtivo = ativo; }

const bool Caixa::getPortalAtivo() const { return PortalAtivo; }

void Caixa::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (!entidade->getEstatico()) {
    entidade->setPos(sf::Vector2f(entidade->getPos().x + mtv.x,
                                  entidade->getPos().y + mtv.y));
    entidade->setPrevPos(sf::Vector2f(entidade->getPrevPos().x + mtv.x * 0.95f,
                                     entidade->getPrevPos().y + mtv.y * 0.95f));
  }
  else{
    pos += mtv;
    pos.x -= vel.x * 0.01;
    prevPos.x += mtv.x * 0.95f;
    prevPos.y += mtv.y * 0.95f;
  }
  if (entidade->getId() == Entidades::ID::jogador) {
    Entidades::Personagens::Jogador *pJog =
        static_cast<Entidades::Personagens::Jogador *>(entidade);
    if (danoso) {
      pJog->operator--(farpas);
      danoso = false;
    }
  }
}
void Caixa::executar() {
  animacao();
  body->setPosition(pos);
  if (prevPos != pos)
    gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}
void Caixa::update() {
  danoTime += gFisico->getDeltaTime();

  if (danoTime > 2.f) {
    danoso = true;
    danoTime = 0;
  }
  executar();
}

void Caixa::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 6 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Tamanho\": [" << this->getSize().x << ", "
             << this->getSize().y << "], \"Textura\": [ " << idTextura
             << " ], \"PortalAtivo\": [" << PortalAtivo << "], \"DanoTime\": ["
             << danoTime << "], \"Danoso\": [" << danoso << "] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades
