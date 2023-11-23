#pragma once

// #include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Personagens/Inimigo/Guerreiro.hpp"
#include "Entidades/Personagens/Inimigo/Samurai.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Projetil/Laser.hpp"
#include "Estados/Estado.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Gerenciadores/GerenciadorDeColisao.hpp"
#include "Gerenciadores/GerenciadorDeEvento.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include "Lista/ListaDeEntidades.hpp"

// #include "Observadores/ControleFase.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"
#include "Entidades/Obstaculos/Lava.hpp"
#include "Estados/Estado.hpp"
#include "Estados/MaquinaDeEstado.hpp"

// #include "Observadores/ControleJogador.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define ARQUIVO_ENTIDADES "data/Save/arquivoEntidades.json"
#define ARQUIVO_FASE "data/Save/arquivoFase.json"
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
  // Observadores::ControleFase* controleFase;
  Entidades::Personagens::Jogador *pJogador;
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
  void newInimigo(sf::Vector2f pos, sf::Vector2f size);
  void newInimigoMedio(sf::Vector2f pos, sf::Vector2f size);
  void newChefao(sf::Vector2f pos, sf::Vector2f size);
  void newProjetil(sf::Vector2f pos, const bool direita);
  void deleteProjetil();
  // void newPlataforma(sf::Vector2f pos, sf::Vector2f size);
  // void newGosma(sf::Vector2f pos, sf::Vector2f size);
  virtual void recuperarJogada(nlohmann::json arquivoEntidades,
                               nlohmann::json arquivoFase) = 0;
  void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
  void setPontuacaoJog(const unsigned int pontos);
  const unsigned int getPontuacaoJog() const;
  void atualizaPontuacao();
  void updateVida();
  void update(double dt);
  void executar();
  void draw();
  // virtual void resetEstate() = 0;
  virtual void loadMap() = 0;
};
} // namespace Fases
