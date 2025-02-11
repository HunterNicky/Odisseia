#include "Fases/Fase_Castelo.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Fases/Fase_Planicie.hpp"

#include <stdlib.h>
#define CAMINHO_BLOCO_GRAMA "data/Sprites/blocos/grass.png"
#define CAMINHO_BLOCO_TERRA "data/Sprites/blocos/dirt.png"
#define CAMINHO_BLOCO_PEDRA "data/Sprites/blocos/cobblestone.png"
#define CAMINHO_BLOCO_PEDRA_R "data/Sprites/blocos/roadcobblestone.png"
#define CAMINHO_BLOCO_PEDRA_V "data/Sprites/blocos/woodplataformcobblestone.png"
#define CAMINHO_BLOCO_PORTAL "data/Sprites/blocos/buracoNegro.png"
#define CAMINHO_BLOCO_CAIXA "data/Sprites/blocos/caixa.png"
namespace Fases {
Fase_Castelo::Fase_Castelo(const int numJogadores) : Fase(2, numJogadores), escaldante(0.8) {
  srand(time(NULL));
  loadMap();
  pJogador->setEstamina(escaldante);
  carregarFundo();
}

Fase_Castelo::Fase_Castelo(nlohmann::json arquivoEntidades, nlohmann::json arquivoFase)
    : Fase(2, arquivoFase[0]["NumJogadores"][0]), escaldante(0.8) {
  carregarFundo();
  recuperarJogada(arquivoEntidades, arquivoFase);
}

Fase_Castelo::~Fase_Castelo() {}

void Fase_Castelo::newLava(sf::Vector2f pos, sf::Vector2f size) {
  Entidades::Obstaculos::Lava *pLava =
      new Entidades::Obstaculos::Lava(pos, size, Entidades::ID::Lava);
  pLava->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pLava));
}
void Fase_Castelo::newSamurai(sf::Vector2f pos, sf::Vector2f size) {
  if (pJogador == nullptr) {
    std::cout << "Erro em criar Samurai!" << std::endl;
    exit(1);
  }
  Entidades::Personagens::Samurai *pSamurai =
      new Entidades::Personagens::Samurai(pos, size, Entidades::ID::Samurai,
                                          this->pJogador);
  pSamurai->setConcreteGerenciadorColisao(pColisao);
  LE.push_back(static_cast<Entidades::Entidade *>(pSamurai));
}
void Fase_Castelo::recuperarJogada(nlohmann::json arquivoEntidades,
                                   nlohmann::json arquivoFase) {
  try {
    if (arquivoFase[0]["NumJogadores"][0] == 1) {
      for (int i = 0; i < (int)arquivoEntidades.size(); i++) {
        if (arquivoEntidades[i]["ID"][0] == Entidades::ID::jogador) {
          pJogador = new Entidades::Personagens::Jogador(
              arquivoEntidades, i, Entidades::ID::jogador);
          pJogador->setConcreteGerenciadorColisao(pColisao);
          controleJog->setJogador(pJogador);
          LE.push_back(static_cast<Entidades::Entidade *>(pJogador));
        }
      }
    } else if (arquivoFase[0]["NumJogadores"][0] == 2) {
      bool primeiro = true;
      for (int i = 0; i < (int)arquivoEntidades.size(); i++) {
        if ((arquivoEntidades[i]["ID"][0] == Entidades::ID::jogador) &&
            primeiro) {
          pJogador = new Entidades::Personagens::Jogador(
              arquivoEntidades, i, Entidades::ID::jogador);
          pJogador->setConcreteGerenciadorColisao(pColisao);
          controleJog->setJogador(pJogador);
          LE.push_back(static_cast<Entidades::Entidade *>(pJogador));
          primeiro = false;
        }
        if ((arquivoEntidades[i]["ID"][0] == Entidades::ID::jogador) &&
            (!primeiro)) {
          std::cout << "Jogador " << std::endl;
          pJogador2 = new Entidades::Personagens::Jogador(
              pos, size, Entidades::ID::jogador);
          pJogador2->setConcreteGerenciadorColisao(pColisao);
          controleJog->setJogador2(pJogador2);
          LE.push_back(static_cast<Entidades::Entidade *>(pJogador2));
        }
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
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Lava) {
        Entidades::Obstaculos::Lava *pLava = new Entidades::Obstaculos::Lava(
            arquivoEntidades, i, Entidades::ID::Gosma);
        pLava->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pLava));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Samurai) {
        Entidades::Personagens::Samurai *pSamurai =
            new Entidades::Personagens::Samurai(
                arquivoEntidades, i, Entidades::ID::Samurai, this->pJogador);
        pSamurai->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pSamurai));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Plataforma) {
        Entidades::Obstaculos::Plataforma *pPlataforma =
            new Entidades::Obstaculos::Plataforma(arquivoEntidades, i,
                                                  Entidades::ID::Plataforma);
        pPlataforma->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pPlataforma));
      } else if (arquivoEntidades[i]["ID"][0] == Entidades::ID::Caixa) {
        Entidades::Obstaculos::Caixa *pCaixa = new Entidades::Obstaculos::Caixa(
            arquivoEntidades, i, Entidades::ID::Caixa);
        pCaixa->setConcreteGerenciadorColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade *>(pCaixa));
      }
    }
    // recupera pontuação
    for (int i = 0; i < (int)arquivoFase.size(); i++) {
      setPontuacaoJog(arquivoFase[i]["Pontuacao"][0]);
      numJogadores = arquivoFase[i]["NumJogadores"][0];
    }
  } catch (nlohmann::json::exception &e) {
    std::cout << "ERRO EM RECUPERAR JOGADA!" << std::endl;
    std::cout << e.what() << std::endl;
  }
}

void Fase_Castelo::loadMap() {

  std::ifstream file("data/Mapas/Fase_Castelo.txt");
  sf::Vector2f pos(0.f, 0.f);
  char caracter;

  while (file.get(caracter)) {
    switch (caracter) {
    case ' ':
      pos.x += 200.f;
      pos.y += 10.f;
      break;
    case 'j':
      // pos.x += 200.f;
      newJogador(pos + sf::Vector2f(100.f, -400.f),
                 sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case '1':
      // pos.x += 20.f;
      newGuerreiro(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case '2':
      // pos.x += 20.f;
      newViajante(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case '3':
      // pos.x += 200.f;
      newSamurai(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
      break;
    case 'p':
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA);
      break;
    case 'c': // caixa
      pos.x += 50.f;
      pos.y -= 50.f;
      newCaixa(pos, sf::Vector2f(100.f, 100.f), CAMINHO_BLOCO_CAIXA);
      break;
    case 'd':
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 100.f), CAMINHO_BLOCO_PEDRA_R);
      break;
    case 'e':
      pos.x += 200.f;
      newPlataforma(pos, sf::Vector2f(200.f, 200.f), CAMINHO_BLOCO_PEDRA_V);
      break;
    case 'l':
      pos.x += 200.f;
      newLava(pos, sf::Vector2f(200.f, 200.f));
      break;
    case '@': { // inimigos aleatório
      int sort = (int)rand() % 3;
      if (sort == 0) {
        pos.x += 200.f;
        newSamurai(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
        break;
      } else if (sort == 1) {
        pos.x += 200.f;
        newViajante(pos, sf::Vector2f(TAM_PERSONAGENS_X, TAM_PERSONAGENS_Y));
        break;
      } else {
        break;
      }
    }
    case '#': { // obstaculos aleatórios
      int sort = (int)rand() % 3;
      if (sort == 0) {
        pos.x += 200.f;
        newLava(pos + sf::Vector2f(0, -50.f), sf::Vector2f(200.f, 50.f));
        break;
      } else if (sort == 1) {
        pos.x += 200.f;
        newCaixa(pos, sf::Vector2f(100.f, 100.f), CAMINHO_BLOCO_CAIXA);
        break;
      } else {
        break;
      }
    }
    default:
      pos.x = 0;
      pos.y += 10.f;
      break;
    }
  }
  file.close();
}

void Fase_Castelo::carregarFundo() {
  fundo = new sf::RectangleShape();
  imgFundo = new sf::Texture();
  // link Imagem https://br.pinterest.com/pin/87116574025635564/
  imgFundo = (pGrafico->loadTexture("data\\imagens\\testeFundo.jpg"));
  fundo->setSize(sf::Vector2f(1280.f, 720.f));
  fundo->setTexture(imgFundo);
  fundo->setOrigin(fundo->getSize().x / 2, fundo->getSize().y / 2);
}
void Fase_Castelo::atualizaFundo() {
  sf::Vector2f cameraPos = pGrafico->getViewCenter();
  sf::Vector2f jogadorPos = pJogador->getBody()->getPosition();
  jogadorPos.y -= 100.f;
  sf::Vector2f novaPosCamera = cameraPos + (jogadorPos - cameraPos) * 0.01f;
  fundo->setPosition(novaPosCamera);
  pGrafico->draw(fundo);
}
void Fase_Castelo::draw() {
  atualizaFundo();
  Fase::draw();
}

void Fase_Castelo::update() { executar(); }

void Fase_Castelo::executar() { Fase::executar(); }
} // namespace Fases