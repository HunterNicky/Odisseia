#pragma once

#include "Entidades/Obstaculos/Gosma.hpp"
#include "Fase.hpp"


#define TAM_PERSONAGENS_X 20.f
#define TAM_PERSONAGENS_Y 32.f
namespace Fases {
class Fase_Planicie : public Fase {
private:
  const sf::Vector2f ventania;
public:
  Fase_Planicie(const int numJogadores);
  Fase_Planicie(nlohmann::json arquivosEntidades, nlohmann::json arquivosFase);
  ~Fase_Planicie();
  void newGosma(sf::Vector2f pos, sf::Vector2f size);
  void recuperarJogada(nlohmann::json arquivoEntidades,
                       nlohmann::json arquivosFase);
  void loadMap();
  void carregarFundo();
  void atualizaFundo();
  void draw();
  void update();
  void executar();
};
} // namespace Fases
