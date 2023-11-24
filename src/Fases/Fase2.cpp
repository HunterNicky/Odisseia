#include "Fases/Fase2.hpp"

#include <stdlib.h>
#define CAMINHO_BLOCO_GRAMA "data\\Sprites\\blocos\\grass.png"
#define CAMINHO_BLOCO_TERRA "data\\Sprites\\blocos\\dirt.png"
#define CAMINHO_BLOCO_PEDRA "data\\Sprites\\blocos\\cobblestone.png"
#define CAMINHO_BLOCO_PEDRA_R "data\\Sprites\\blocos\\roadcobblestone.png"
#define CAMINHO_BLOCO_PEDRA_V "data\\Sprites\\blocos\\woodcobblestone.png"
#define CAMINHO_BLOCO_PORTAL "data\\Sprites\\blocos\\buracoNegro.png"
#define CAMINHO_BLOCO_CAIXA "data\\Sprites\\blocos\\caixa.png"
namespace Fases {
Fase2::Fase2() : Fase() { loadMap(); }

Fase2::Fase2(nlohmann::json arquivoEntidades, nlohmann::json arquivoFase)
    : Fase() {
  recuperarJogada(arquivoEntidades, arquivoFase);
}

Fase2::~Fase2() {}

void Fase2::newLava(sf::Vector2f pos, sf::Vector2f size) {
  Entidades::Obstaculos::Lava *pLava =
      new Entidades::Obstaculos::Lava(pos, size, Entidades::ID::Lava);
  pLava->setGerenciadorDeColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pLava));
}
void Fase2::newSamurai(sf::Vector2f pos, sf::Vector2f size) {
  if (pJogador == nullptr) {
    std::cout << "Erro em criar Samurai!" << std::endl;
    exit(1);
  }
  Entidades::Personagens::Samurai *pSamurai =
      new Entidades::Personagens::Samurai(pos, size, Entidades::ID::Samurai,
                                          this->pJogador);
  pSamurai->setGerenciadorDeColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pSamurai));
}
void Fase2::recuperarJogada(nlohmann::json arquivoEntidades,
                            nlohmann::json arquivoFase) {
  for (int i = 0; i < (int)arquivoEntidades.size(); i++) {
    if (arquivoEntidades[i]["ID"][0] == Entidades::ID::jogador) {
      pJogador = new Entidades::Personagens::Jogador(arquivoEntidades, i,
                                                     Entidades::ID::jogador);
      pJogador->setGerenciadorDeColisao(pColisao);
      controleJog->setJogador(pJogador);
      LE.push_back(static_cast<Entidades::Entidade *>(pJogador));
    } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Guerreiro) {
      if (this->pJogador == nullptr) {
        std::cout << "ERRO EM RECUPERAR JOGADA!" << std::endl;
        exit(1);
      }
      Entidades::Personagens::Guerreiro *pInimigo =
          new Entidades::Personagens::Guerreiro(
              arquivoEntidades, i, Entidades::ID::Guerreiro, this->pJogador);
      pInimigo->setGerenciadorDeColisao(pColisao);
      LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
    } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Viajante) {
      if (pJogador == nullptr) {
        std::cout << "ERRO EM RECUPERAR JOGADA! 2" << std::endl;
        exit(1);
      }
      Entidades::Personagens::Viajante *pInimigo =
          new Entidades::Personagens::Viajante(
              arquivoEntidades, i, Entidades::ID::Viajante, this->pJogador);
      pInimigo->setGerenciadorDeColisao(pColisao);
      LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));

      if (pInimigo == nullptr) {
        std::cout << "ERRO EM RECUPERAR JOGADA! Inimigo Viajante" << std::endl;
        exit(1);
      } else {
        for (int j = 0; j < (int)arquivoEntidades.size(); j++) {
          if (arquivoEntidades[j]["ID"][0] == Entidades::ID::Laser) {
            Entidades::Laser *pProjetil = new Entidades::Laser(
                arquivoEntidades, j, Entidades::ID::Laser, pInimigo);
            pProjetil->setGerenciadorDeColisao(pColisao);
            LE.push_back(static_cast<Entidades::Entidade *>(pProjetil));
            pInimigo->setProj(pProjetil);
          }
        }
      }
    } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Samurai) {
      if (pJogador == nullptr) {
        std::cout << "ERRO EM RECUPERAR JOGADA! 3" << std::endl;
        exit(1);
      }
      Entidades::Personagens::Samurai *pInimigo =
          new Entidades::Personagens::Samurai(
              arquivoEntidades, i, Entidades::ID::Samurai, this->pJogador);
      pInimigo->setGerenciadorDeColisao(pColisao);
      LE.push_back(static_cast<Entidades::Entidade *>(pInimigo));
    } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Plataforma) {
      Entidades::Obstaculos::Caixa *pPlataforma =
          new Entidades::Obstaculos::Caixa(arquivoEntidades, i,
                                           Entidades::ID::Plataforma);
      pPlataforma->setGerenciadorDeColisao(pColisao);
      LE.push_back(static_cast<Entidades::Entidade *>(pPlataforma));
    }
  }
  for (int i = 0; i < (int)arquivoFase.size(); i++) {
    setPontuacaoJog(arquivoFase[i]["Pontuacao"][0]);
  }
}

void Fase2::loadMap() {

  std::ifstream file("data\\Mapas\\fase2.txt");
  sf::Vector2f pos(0.f, 0.f);
  char caracter;

  while (file.get(caracter)) {
    switch (caracter) {
    case '0':
      pos.x += 200.f;
      pos.y += 10.f;
      break;
    case 'j':
      pos.x += 200.f;
      newJogador(pos + sf::Vector2f(100.f, 0.f), sf::Vector2f(60.f, 96.f));
      break;
    case '1':
      pos.x += 20.f;
      newGuerreiro(pos, sf::Vector2f(60.f, 96.f));
      break;
    case '2':
      pos.x += 20.f;
      newViajante(pos, sf::Vector2f(60.f, 96.f));
      break;
    case '3':
      pos.x += 200.f;
      newSamurai(pos, sf::Vector2f(60.f, 96.f));
      break;
    case 'p':
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA);
      break;
    case 'a': // grama
      pos.x += 200.f;
      newCaixa(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_GRAMA);
      break;
    case 'b': // terra
      pos.x += 200.f;
      newCaixa(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_TERRA);
      break;
    case 'c': // caixa
      pos.x += 200.f;
      newCaixa(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_CAIXA);
      break;
    case 'd':
      pos.x += 200.f;
      newCaixa(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA);
      break;
    case 'e':
      pos.x += 200.f;
      newCaixa(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA_R);
      break;
    case 'l':
      pos.x += 200.f;
      newLava(pos, sf::Vector2f(200.f, 200.f));
      break;
    default:
      pos.x = 0;
      pos.y += 10.f;
      break;
    }
  }
  file.close();
}
void Fase2::draw() { Fase::draw(); }

void Fase2::update() { executar(); }

void Fase2::executar() { Fase::executar(); }
} // namespace Fases