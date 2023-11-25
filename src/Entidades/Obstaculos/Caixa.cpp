#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"

namespace Entidades {
namespace Obstaculos {
Caixa::Caixa(const sf::Vector2f pos, const sf::Vector2f size,
             const Entidades::ID id, const std::string path)
    : Obstaculo(pos, size, id), PortalAtivo(false),
      bloco(static_cast<Entidades::Entidade *>(this), path, 2,
            sf::Vector2f(1, 1)),
      contexto() {
  contexto.setStrategy(&bloco, 1.f);
  this->body->setFillColor(sf::Color::White);
  if(path == CAMINHO_BLOCO_PORTAL){
    PortalAtivo = true;
  }else{
    PortalAtivo = false;
  }
}

Caixa::Caixa(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this),
             CAMINHO_BLOCO_GRAMA, 1, sf::Vector2f(1, 1)),
      contexto() {
  contexto.setStrategy(&bloco, 0.5f);
  this->body->setFillColor(sf::Color::White);
}
Caixa::~Caixa() {}

void Caixa::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

void Caixa::colocarTextura() {
  texturas.clear();

  texturas.push_back(CAMINHO_BLOCO_GRAMA);
  texturas.push_back(CAMINHO_BLOCO_TERRA);
  texturas.push_back(CAMINHO_BLOCO_PEDRA);
  texturas.push_back(CAMINHO_BLOCO_PEDRA_R);
  texturas.push_back(CAMINHO_BLOCO_PEDRA_V);
  texturas.push_back(CAMINHO_BLOCO_PORTAL);
}

void Caixa::setPortalAtivo(const bool ativo) { PortalAtivo = ativo; }

const bool Caixa::getPortalAtivo() const { return PortalAtivo; }

void Caixa::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  entidade->setPos(sf::Vector2f(entidade->getPos().x + mtv.x, entidade->getPos().y + mtv.y));
  entidade->setPrevPos(sf::Vector2f(entidade->getPrevPos().x + mtv.x * 0.9, entidade->getPrevPos().y + mtv.y * 0.9));
}

void Caixa::executar() { animacao(); }

void Caixa::update() { executar(); }

void Caixa::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 5 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Tamanho\": [" << this->getSize().x << ", "
             << this->getSize().y << "], \"Textura\": [ "<< 0 <<" ] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades
