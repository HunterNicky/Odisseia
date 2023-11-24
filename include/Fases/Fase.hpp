#pragma once

#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Personagens/Inimigo/Guerreiro.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Projetil/Laser.hpp"
#include "Estados/Estado.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Gerenciadores/GerenciadorDeColisao.hpp"
#include "Gerenciadores/GerenciadorDeEvento.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include "Lista/ListaDeEntidades.hpp"

// #include "Observadores/ControleJogador.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define ARQUIVO_ENTIDADES "data/Save/arquivoEntidades.json"
#define ARQUIVO_FASE "data/Save/arquivoFase.json"
#define CAMINHO_FONTE_PONTUACAO "data/Font/menus.ttf"
namespace Observadores {
class ControleJogador;

}
namespace Fases {
class Fase : public Estados::Estado {
protected:
  static Gerenciadores::GerenciadorGrafico *pGrafico;
  static Gerenciadores::GerenciadorDeEvento *pEvento;
  static Gerenciadores::GerenciadorFisico *pFisico;
  static Gerenciadores::GerenciadorDeColisao *pColisao;
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  Observadores::ControleJogador *controleJog;
  Entidades::Personagens::Jogador *pJogador;
  sf::RectangleShape *barraDeVida;
  sf::RectangleShape *tuboVida;
  Lista::ListaDeEntidades LE;
  std::ostringstream buffer;
  unsigned int pontuacao_jogador;
  static Menu::Botoes::Texto textoPontuacao;
  double dt;

public:
  Fase();
  ~Fase();
  void salvarEntidades();
  void salvarAtributosFase();
  void newJogador(sf::Vector2f pos, sf::Vector2f size);
  void newGuerreiro(sf::Vector2f pos, sf::Vector2f size);
  void newViajante(sf::Vector2f pos, sf::Vector2f size);
  void newPlataforma(sf::Vector2f pos, sf::Vector2f size,
                     const std::string path);
  void newCaixa(sf::Vector2f pos, sf::Vector2f size, const std::string path);
  void setPontuacaoJog(const unsigned int pontos);
  const unsigned int getPontuacaoJog() const;
  void atualizaPontuacao();
  void atualizaBarraDeVida();
  void proximaFase();
  void updateVida();
  void update(double dt);
  void executar();
  void draw();
  // virtual void resetEstate() = 0;
  virtual void recuperarJogada(nlohmann::json arquivoEntidades,
                               nlohmann::json arquivoFase) = 0;
  virtual void loadMap() = 0;
};
} // namespace Fases
