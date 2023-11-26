#include "Fases/Fase.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include "Fases/Fase2.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "Observadores/ControleJogador.hpp"
#define CAMINHO_BLOCO_PORTAL "data\\Sprites\\blocos\\buracoNegro.png"

#include <list>
#include <ostream>
#include <sstream>

namespace Fases {
Gerenciadores::GerenciadorGrafico *Fase::pGrafico =
    Gerenciadores::GerenciadorGrafico::getInstance();
Gerenciadores::GerenciadorDeEvento *Fase::pEvento =
    Gerenciadores::GerenciadorDeEvento::getInstance();
Gerenciadores::Colisao::CalculadorFisico *Fase::pFisico =
    Gerenciadores::Colisao::CalculadorFisico::getInstance();
Gerenciadores::Colisao::ConcreteGerenciadorColisao *Fase::pColisao =
    Gerenciadores::Colisao::ConcreteGerenciadorColisao::getInstance();
Estados::MaquinaDeEstado *Fase::pMaquinaDeEstado =
    Estados::MaquinaDeEstado::getInstance();
Menu::Botoes::Texto Fase::textoPontuacao(sf::Vector2f(0.f, 0.f),
                                         sf::Vector2f(50.f, 50.f), "", 35);

Fase::Fase(const int idFase) : Estado(pMaquinaDeEstado, 1) {
  pJogador = nullptr;
  controleJog = new Observadores::ControleJogador(
      pJogador, static_cast<Fases::Fase *>(this));
  pColisao->setList(&LE);
  pEvento->addObserver(static_cast<Observadores::Observer *>(controleJog));
  dt = 0.f;
  pontuacao_jogador = 0;
  this->idFase = idFase;
  textoPontuacao.setColor(sf::Color::White);
  textoPontuacao.setTextFont(CAMINHO_FONTE_PONTUACAO);
  if (textoPontuacao.getText() == "") {
    textoPontuacao.setTexto("Score: 00000");
    textoPontuacao.setTamanhoBorda(2.f);
  }
  inicializaVidaJog();
}
Fase::~Fase() {
  salvarEntidades();
  salvarAtributosFase();
  for (unsigned int i = 0; i < LE.getSize(); i++) {
    LE.remove(i);
  }
  LE.clear();
  pEvento->removeObserver(static_cast<Observadores::Observer *>(controleJog));
}

void Fase::salvarEntidades() {
  std::ofstream arquivo(ARQUIVO_ENTIDADES);
  if (!arquivo) {
    std::cout << "Erro ao abrir arquivo" << std::endl;
    exit(1);
  }
  // salvar Entidades
  buffer.str("");
  buffer << "[";

  if (LE[0] != nullptr) {
    LE[0]->salvar(&buffer);
  }
  for (unsigned int i = 1; i < LE.getSize(); i++) {
    buffer << ",";
    LE[i]->salvar(&buffer);
  }

  buffer << "]";
  arquivo << buffer.str() << std::endl;
  arquivo.close();
}
void Fase::salvarAtributosFase() {
  // Salvando pontuação
  std::ofstream arquivo(ARQUIVO_FASE);
  if (!arquivo) {
    std::cout << "Erro ao abrir arquivo" << std::endl;
    exit(1);
  }

  buffer.str("");
  buffer << "[";

  buffer << "{ \"IdFase\": [" << idFase << "], \"Pontuacao\": [" << getPontuacaoJog() << "] }" << std::endl;

  buffer << "]";
  arquivo << buffer.str() << std::endl;
  arquivo.close();
}
void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size) {
  pJogador =
      new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
  pJogador->setConcreteGerenciadorColisao(pColisao);
  controleJog->setJogador(pJogador);
  LE.push_back(static_cast<Entidades::Entidade *>(pJogador));
}
void Fase::newGuerreiro(sf::Vector2f pos, sf::Vector2f size) {
  Entidades::Personagens::Guerreiro *pInimigo =
      new Entidades::Personagens::Guerreiro(pos, size, Entidades::ID::Guerreiro,
                                            pJogador);
  pInimigo->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
}
void Fase::newViajante(sf::Vector2f pos, sf::Vector2f size) {
  Entidades::Personagens::Viajante *pInimigo =
      new Entidades::Personagens::Viajante(pos, size, Entidades::ID::Viajante,
                                           pJogador, nullptr);
  pInimigo->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
  pInimigo->setFase(this);
}
void Fase::newPlataforma(sf::Vector2f pos, sf::Vector2f size,
                         const std::string path) {
  Entidades::Obstaculos::Plataforma *pPlataforma = new Entidades::Obstaculos::Plataforma(
      pos, size, Entidades::ID::Plataforma, path);
  pPlataforma->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pPlataforma));
}
void Fase::newCaixa(sf::Vector2f pos, sf::Vector2f size,
                    const std::string path) {
  Entidades::Obstaculos::Caixa *pCaixa =
      new Entidades::Obstaculos::Caixa(pos, size, Entidades::ID::Caixa, path);
  pCaixa->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pCaixa));
  if (path == CAMINHO_BLOCO_PORTAL) {
    pCaixa->setPortalAtivo(true);
  }
}
void Fase::newProjetil(const sf::Vector2f pos, const sf::Vector2f vel){
  Entidades::Laser *pProj =
      new Entidades::Laser(pos, vel, Entidades::ID::Laser);
  pProj->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pProj));
}

void Fase::setPontuacaoJog(const unsigned int pontos) {
  this->pontuacao_jogador = pontos;
  std::string score = std::to_string(this->pontuacao_jogador);
  while (score.size() < 5) {
    std::string aux = score;
    score = '0' + aux;
  }
  textoPontuacao.setTexto("Score: " + score);
}
const unsigned int Fase::getPontuacaoJog() const { return pontuacao_jogador; }

void Fase::atualizaPontuacao() {
  sf::Vector2f posFundo = pGrafico->getViewCenter();
  sf::Vector2f tamJan = sf::Vector2f(1280.f, 720.f);
  textoPontuacao.setPos(
      sf::Vector2f(posFundo.x - tamJan.x / 4, posFundo.y - tamJan.y / 2));
  pGrafico->drawText(textoPontuacao.getSfTexto());
}

void Fase::inicializaVidaJog() {
  barraDeVida = new sf::RectangleShape();
  tuboVida = new sf::RectangleShape();
  sf::Vector2f tamTubo = sf::Vector2f(BARRA_VIDA_JOG_X, BARRA_VIDA_JOG_Y);
  tuboVida->setSize(tamTubo);
  barraDeVida->setSize(tamTubo);
  sf::Texture *texturaVida = new sf::Texture();
  sf::Texture *texturaBarra = new sf::Texture();
  texturaVida->loadFromFile("data\\Vida\\barraDeVida.png");
  texturaBarra->loadFromFile("data\\Vida\\BarraVidaJog.png");
  barraDeVida->setTexture(texturaVida);
  tuboVida->setTexture(texturaBarra);
}

void Fase::atualizaBarraDeVidaJog() {
  sf::Vector2f posFundo = pGrafico->getViewCenter();
  sf::Vector2f tamJan = sf::Vector2f(1280.f, 720.f);
  barraDeVida->setPosition((sf::Vector2f(posFundo.x - tamJan.x / 2 + 45.f,
                                         posFundo.y - tamJan.y / 2 + 19.f)));
  tuboVida->setPosition(
      sf::Vector2f(posFundo.x - tamJan.x / 2, posFundo.y - tamJan.y / 2));
  barraDeVida->setSize(sf::Vector2f((BARRA_VIDA_JOG_X - 50.f) *
                                        pJogador->getNum_vidas() / 1000.f,
                                    BARRA_VIDA_JOG_Y - 39.f));

  pGrafico->draw(static_cast<sf::Drawable *>(barraDeVida));
  pGrafico->draw(static_cast<sf::Drawable *>(tuboVida));
}

void Fase::atualizaBarraDeVidaIni() {
  for(unsigned int i = 0; i<LE.getSize(); i++) {
    if((LE[i]->getId() == Entidades::ID::Guerreiro) || (LE[i]->getId() == Entidades::ID::Viajante) || (LE[i]->getId() == Entidades::ID::Samurai)){
      Entidades::Personagens::Personagem* pPerso = static_cast<Entidades::Personagens::Personagem*>(LE[i]);
      pPerso->atualizaBarraDeVida();
    }
  }
}
void Fase::atualizaProjetil(){
  for(unsigned int i = 0; i < LE.getSize(); i++){
    if(LE[i]->getId() == Entidades::ID::Laser){
      Entidades::Laser* pProj = static_cast<Entidades::Laser*>(LE[i]);
      if(!pProj->getAtivo()){
        LE.remove(i);
      }
    }
  }
}

void Fase::update(double dt) {
  this->dt = dt;
  executar();
}
void Fase::proximaFase() {
  // Passar de fase
  if (pJogador->getProximaFase()){
    //desempilha estado anterior
    pMaquinaDeEstado->popEstado();

    //empilha o estado de fase 2
    Fases::Fase2* pFase = new Fases::Fase2();
    pMaquinaDeEstado->pushEstado(pFase);
  }
  
}

void Fase::updateVida() {
  for (unsigned int i = 0; i < LE.getSize(); i++) {
    if ((LE[i]->getId() == Entidades::ID::Guerreiro || LE[i]->getId() == Entidades::ID::Viajante) || (LE[i]->getId() == Entidades::ID::Samurai)) {
      Entidades::Personagens::Personagem *pPers =
          static_cast<Entidades::Personagens::Personagem *>(LE[i]);
      if (pPers->getNum_vidas() < 0) {
        LE.remove(i);
        setPontuacaoJog(getPontuacaoJog() + 200);
      }
    }
    if (LE[i]->getId() == Entidades::ID::jogador) {
      // remover Jogador
      Entidades::Personagens::Personagem *pPers =
          static_cast<Entidades::Personagens::Personagem *>(LE[i]);
      if (pPers->getNum_vidas() < 0) {
        controleJog->jogadorNeutralizado();
        LE.remove(i);
      }
    }
  }
}

void Fase::executar() {
  if (pJogador) {
    sf::Vector2f cameraPos = pGrafico->getViewCenter();
    sf::Vector2f jogadorPos = pJogador->getBody()->getPosition();
    jogadorPos.y -= 100.f;
    sf::Vector2f novaPosCamera = cameraPos + (jogadorPos - cameraPos) * 0.01f;
    pGrafico->setViewCenter(novaPosCamera);
    pFisico->update(dt);
    for (unsigned int i = 0; i < LE.getSize(); i++) {
      pFisico->executarFisica(LE.operator[](i));
    }
    updateVida();
    draw();
    LE.updateAll();
  }
}
void Fase::draw() {
  //pGrafico->draw(static_cast<sf::Drawable*>(fundo));
  LE.drawAll();
  atualizaPontuacao();
  atualizaBarraDeVidaJog();
  atualizaBarraDeVidaIni();
  atualizaProjetil();
  proximaFase();
}
} // namespace Fases
