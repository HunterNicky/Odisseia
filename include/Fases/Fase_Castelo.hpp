#pragma once

#include "Entidades/Obstaculos/Lava.hpp"
#include "Entidades/Personagens/Inimigo/Samurai.hpp"
#include "Fase.hpp"
#include "Observadores/ControleJogador.hpp"


namespace Fases {
class Fase_Castelo : public Fase {
private:
  float escaldante;
public:
  Fase_Castelo();
  Fase_Castelo(nlohmann::json arquivoEntidades, nlohmann::json arquivoFase);
  ~Fase_Castelo();
  void newLava(sf::Vector2f pos, sf::Vector2f size);
  void newSamurai(sf::Vector2f pos, sf::Vector2f size);
  void recuperarJogada(nlohmann::json arquivoEntidades,
                       nlohmann::json arquivoFase);
  void loadMap();
  void carregarFundo();
  void atualizaFundo();
  void draw();
  void update();
  void executar();
};
} // namespace Fases