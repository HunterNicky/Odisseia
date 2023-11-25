#pragma once

#include "Entidades/Obstaculos/Gosma.hpp"
#include "Fase.hpp"


#define TAM_PERSONAGENS_X 20.f
#define TAM_PERSONAGENS_Y 32.f
namespace Fases {
class Fase1 : public Fase {
public:
  Fase1();
  Fase1(nlohmann::json arquivosEntidades, nlohmann::json arquivosFase);
  ~Fase1();
  void newGosma(sf::Vector2f pos, sf::Vector2f size);
  void recuperarJogada(nlohmann::json arquivoEntidades,
                       nlohmann::json arquivosFase);
  void loadMap();
  void carregarFundo();
  void draw();
  void update();
  void executar();
};
} // namespace Fases
