#pragma once

#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"
#include "Entidades/Personagens/Inimigo/Guerreiro.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"
#include "Entidades/Personagens/Jogador/Jogador.hpp"
#include "Entidades/Projetil/Laser.hpp"
#include "Estados/Estado.hpp"
#include "Estados/MaquinaDeEstado.hpp"
#include "Gerenciadores/Colisao/CalculadorFisico.hpp"
#include "Gerenciadores/Colisao/ConcreteGerenciadorColisao.hpp"
#include "Gerenciadores/GerenciadorDeEvento.hpp"
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
  static Gerenciadores::Colisao::CalculadorFisico *pFisico;
  static Gerenciadores::Colisao::ConcreteGerenciadorColisao *pColisao;
  static Estados::MaquinaDeEstado *pMaquinaDeEstado;
  Observadores::ControleJogador *controleJog;
  static Entidades::Personagens::Jogador *pJogador;
  static Entidades::Personagens::Jogador *pJogador2;
  sf::RectangleShape *barraDeVida;
  sf::RectangleShape *tuboVida;
  sf::RectangleShape *fundo;
  sf::Texture *imgFundo;
  Lista::ListaDeEntidades LE;
  std::ostringstream buffer;
  unsigned int pontuacao_jogador;
  static Menu::Botoes::Texto textoPontuacao;
  double dt;
  int idFase;
  int numJogadores;

public:
  Fase(const int idFase, const int numJogadores);
  ~Fase();
  void salvarEntidades();
  void salvarAtributosFase();
  void newJogador(sf::Vector2f pos, sf::Vector2f size);
  void newGuerreiro(sf::Vector2f pos, sf::Vector2f size);
  void newViajante(sf::Vector2f pos, sf::Vector2f size);
  void newPlataforma(sf::Vector2f pos, sf::Vector2f size,
                     const std::string path);
  void newCaixa(sf::Vector2f pos, sf::Vector2f size, const std::string path);
  void newProjetil(const sf::Vector2f pos, const sf::Vector2f vel);
  void setPontuacaoJog(const unsigned int pontos);
  const unsigned int getPontuacaoJog() const;
  void atualizaPontuacao();
  void inicializaVidaJog();
  void atualizaBarraDeVidaJog();
  void atualizaBarraDeVidaIni();
  void atualizaProjetil();
  void proximaFase();
  void updateVida();
  void update(double dt);
  void executar();
  void draw();
  virtual void recuperarJogada(nlohmann::json arquivoEntidades,
                               nlohmann::json arquivoFase) = 0;
  virtual void loadMap() = 0;
  virtual void carregarFundo() = 0;
  virtual void atualizaFundo() = 0;
};
} // namespace Fases
