#include "Fases/Fase1.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Fases/Fase.hpp"
#include "Observadores/ControleJogador.hpp"
#include <stdlib.h>

#define CAMINHO_BLOCO_GRAMA "data/Sprites/blocos/grass.png"
#define CAMINHO_BLOCO_TERRA "data/Sprites/blocos/dirt.png"
#define CAMINHO_BLOCO_PEDRA "data/Sprites/blocos/cobblestone.png"
#define CAMINHO_BLOCO_PEDRA_R "data/Sprites/blocos/roadcobblestone.png"
#define CAMINHO_BLOCO_PEDRA_V "data/Sprites/blocos/woodplataformcobblestone.png"
#define CAMINHO_BLOCO_PORTAL "data/Sprites/blocos/buracoNegro.png"
#define CAMINHO_BLOCO_CAIXA "data/Sprites/blocos/caixa.png"
namespace Fases {
Fase1::Fase1() : Fase(1) {
  srand(time(NULL));
  loadMap();
  carregarFundo();
}
Fase1::Fase1(nlohmann::json arquivosEntidades, nlohmann::json arquivosFase)
    : Fase(1) {
  recuperarJogada(arquivosEntidades, arquivosFase);
}
Fase1::~Fase1() {}
void Fase1::newGosma(sf::Vector2f pos, sf::Vector2f size) {
  Entidades::Obstaculos::Gosma *pGosma =
      new Entidades::Obstaculos::Gosma(pos, size, Entidades::ID::Gosma);
  pGosma->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pGosma));
}
void Fase1::recuperarJogada(nlohmann::json arquivoEntidades,
                            nlohmann::json arquivoFase) {
  try { // recupera entidades
    for (int i = 0; i < (int)arquivoEntidades.size(); i++) {
      if (arquivoEntidades[i]["ID"][0] == Entidades::ID::jogador) {
        pJogador = new Entidades::Personagens::Jogador(arquivoEntidades, i,
                                                       Entidades::ID::jogador);
        pJogador->setConcreteGerenciadorColisao(pColisao);
        controleJog->setJogador(pJogador);
        LE.push_back(static_cast<Entidades::Entidade *>(pJogador));
      }
    }
    for (int i = 0; i < (int)arquivoEntidades.size(); i++) {
      if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Guerreiro) {
        Entidades::Personagens::Guerreiro *pInimigo =
            new Entidades::Personagens::Guerreiro(
                arquivoEntidades, i, Entidades::ID::Guerreiro, this->pJogador);
        pInimigo->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Viajante) {
        Entidades::Personagens::Viajante *pInimigo =
            new Entidades::Personagens::Viajante(
                arquivoEntidades, i, Entidades::ID::Viajante, this->pJogador);
        pInimigo->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
        pInimigo->setFase(static_cast<Fases::Fase *>(this)); // seleciona fase
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Laser) {
        Entidades::Laser *pProjetil =
            new Entidades::Laser(arquivoEntidades, i, Entidades::ID::Laser);
        pProjetil->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pProjetil));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Gosma) {
        Entidades::Obstaculos::Gosma *pGosma = new Entidades::Obstaculos::Gosma(
            arquivoEntidades, i, Entidades::ID::Gosma);
        pGosma->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pGosma));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Plataforma) {
        Entidades::Obstaculos::Plataforma *pPlataforma =
            new Entidades::Obstaculos::Plataforma(arquivoEntidades, i,
                                             Entidades::ID::Plataforma);
        pPlataforma->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pPlataforma));
      }else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Caixa) {
        Entidades::Obstaculos::Caixa *pCaixa =
            new Entidades::Obstaculos::Caixa(arquivoEntidades, i,
                                             Entidades::ID::Caixa);
        pCaixa->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pCaixa));
      }
    }
    // recupera pontuação
    for (int i = 0; i < (int)arquivoFase.size(); i++) {
      setPontuacaoJog(arquivoFase[i]["Pontuacao"][0]);
    }
  } catch (nlohmann::json::exception &e) {
    std::cout << "ERRO EM RECUPERAR JOGADA!" << std::endl;
    std::cout << e.what() << std::endl;
  }
}
void Fase1::loadMap() {
  std::ifstream file("data/Mapas/fase1.txt");
  sf::Vector2f pos(0.f, 0.f);
  char caracter;

  while (file.get(caracter)) {
    switch (caracter) {
    case '0':
      pos.x += 200.f;
      break;
    case 'j':
      // pos.x += 200.f;
      newJogador(pos + sf::Vector2f(100.f, -200.f),
                 sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case '1':
      newGuerreiro(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case '2':
      newViajante(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case 'a': // grama
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 200.f), CAMINHO_BLOCO_GRAMA);
      break;
    case 'b': // terra
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_TERRA);
      break;
    case 'p':
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA);
      break;
    case 'c':
      pos.x += 50.f;
      newCaixa(pos, sf::Vector2f(50.f, 50.f), CAMINHO_BLOCO_CAIXA);
      break;
    case 'g':
      pos.x += 200.0f;
      newGosma(pos, sf::Vector2f(200.f, 200.f));
      break;
    case 'w':
      pos.x += 200.0f;
      newCaixa(pos, sf::Vector2f(50.f, 100.f), CAMINHO_BLOCO_PORTAL);
      break;
    case '@': {                   // inimigos aleatório
      int sort = (int)rand() % 3; // 33% de chance
      if (sort == 0) {
        pos.x += 200.f;
        newGuerreiro(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
        break;
      } else if (sort == 1) {
        pos.x += 200.f;
        newViajante(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
        break;
      } else {
        break;
      }
    }
    case '#': {                   // obstaculos aleatórios
      int sort = (int)rand() % 3; // 33% de chance
      if (sort == 0) {
        pos.x += 200.f;
        newGosma(pos, sf::Vector2f(200.f, 100.f));
        break;
      } else if (sort == 1) {
        pos.x += 50.f;
        newCaixa(pos, sf::Vector2f(50.f, 50.f), CAMINHO_BLOCO_CAIXA);
        break;
      } else {
        break;
      }
    }
    case ' ':
      pos.x += 200.f;
      pos.y += 10.0f;
      break;
    default:
      pos.x = 0;
      break;
    }
  }
  file.close();
}

void Fase1::carregarFundo() {
  fundo = new sf::RectangleShape();
  imgFundo = new sf::Texture();
  fundo->setSize(sf::Vector2f(1280.f, 640.f));
  fundo->setPosition(
      sf::Vector2f(pGrafico->getViewCenter().x, pGrafico->getViewCenter().y));
  imgFundo->loadFromFile("data/imagens/fundoFase1.png");
  pGrafico->draw(fundo);
  // pGrafico->draw(fundo)
}
void Fase1::draw() { Fase::draw(); }

void Fase1::update() { executar(); }

void Fase1::executar() { Fase::executar(); }
} // namespace Fases