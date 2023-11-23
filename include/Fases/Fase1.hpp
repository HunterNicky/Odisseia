#pragma once

#include "Fase.hpp"
#include "Fases/json.hpp"

#define TAM_PERSONAGENS_X 32.f
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
  void draw();
  void update();
  void executar();
};
} // namespace Fases
