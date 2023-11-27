#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Entidades {
namespace Obstaculos {
Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f size,
             const Entidades::ID id, const std::string path)
    : Obstaculo(pos, size, id),
      bloco(static_cast<Entidades::Entidade *>(this), path, 5,
            sf::Vector2f(1, 1)),
      contexto() {
  contexto.setStrategy(&bloco, 1.f);
  this->body->setFillColor(sf::Color::White);
  idTextura = setarIdTextura(path);
  danoso = false;
}

Plataforma::Plataforma(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this), 5,
            sf::Vector2f(1, 1)),
      contexto() {
  this->idTextura = atributos[pos]["Textura"][0];
  bloco.setTexture(colocarTextura(idTextura));
  contexto.setStrategy(&bloco, 1.f);
  this->body->setFillColor(sf::Color::White);
  danoso = false;
}
Plataforma::~Plataforma() {}

void Plataforma::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

std::string Plataforma::colocarTextura(int idText) {
  if(idText == 0) {
    return CAMINHO_BLOCO_GRAMA;
  }else if(idText == 1) {
    return CAMINHO_BLOCO_TERRA;
  }else if(idText == 2) {
    return CAMINHO_BLOCO_PEDRA;
  }else if(idText == 3) {
    return CAMINHO_BLOCO_PEDRA_R;
  }else if(idText == 4) {
    return CAMINHO_BLOCO_PEDRA_V;
  }else {
    return "";
  }
}

int Plataforma::setarIdTextura(const std::string path){
  if(path == CAMINHO_BLOCO_GRAMA){
    return 0;
  }else if(path == CAMINHO_BLOCO_TERRA){
    return 1;
  }else if(path == CAMINHO_BLOCO_PEDRA){
    return 2;
  }else if(path == CAMINHO_BLOCO_PEDRA_R){
    return 3;
  }else if(path == CAMINHO_BLOCO_PEDRA_V){
    return 4;
  }else{
    return -1;
  }
}

void Plataforma::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (!entidade->getEstatico()) {
    entidade->setPos(sf::Vector2f(entidade->getPos().x + mtv.x,
                                  entidade->getPos().y + mtv.y));
    entidade->setPrevPos(sf::Vector2f(entidade->getPrevPos().x + mtv.x * 0.9f,
                                     entidade->getPrevPos().y + mtv.y * 0.9f));
  }
  else{
    pos += mtv;
    pos.x -= vel.x * 0.01;
    prevPos.x += mtv.x * 0.9f;
    prevPos.y += mtv.y * 0.9f;
  }
}
void Plataforma::executar() {
  animacao();
  body->setPosition(pos);
  if (prevPos != pos)
    gColisao->Notify(static_cast<Entidades::Entidade *>(this));
}
void Plataforma::update() { executar(); }

void Plataforma::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 5 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "], \"Tamanho\": [" << this->getSize().x << ", "
             << this->getSize().y << "], \"Textura\": [ " << idTextura << " ] }" 
             << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades
