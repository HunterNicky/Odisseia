#pragma once

#include "Fase.hpp"
#include "Fases/Fase.hpp"
#include "Observadores/ControleJogador.hpp"
namespace Fases {
class Fase2 : public Fase {
private:
public:
  Fase2();
  Fase2(nlohmann::json arquivoEntidades, nlohmann::json arquivoFase);
  ~Fase2();
  void newLava(sf::Vector2f pos, sf::Vector2f size);
  void recuperarJogada(nlohmann::json arquivoEntidades,
                       nlohmann::json arquivoFase);
  void loadMap();
  void draw();
  void update();
  void executar();
};
} // namespace Fases