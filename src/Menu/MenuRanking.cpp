#include "Menu/MenuRanking.hpp"
#include <fstream>

namespace Menu {
MenuRanking::MenuRanking()
    : Menu(3, 1,
           sf::Vector2f(POS_TEXTO_RANKING_X - TAM_TEXTO_RANKING_X * 2,
                        POS_TEXTO_RANKING_Y - TAM_TEXTO_RANKING_Y),
           sf::Vector2f(TAM_TEXTO_RANKING_X, TAM_TEXTO_RANKING_Y), "RANKING",
           150),
      vectorTexto() {
  inicializaBotao();
  titulo.setColor(sf::Color::Green);
  titulo.setTextFont(CAMINHO_FONTE_RANKING);
  criarRanking();
}
MenuRanking::~MenuRanking() {}

// Ideia de código monitor Giovane
void MenuRanking::criarTexto(std::string linha) {
  std::string espaco = " ";
  size_t pos = 0;
  std::vector<std::string> palavras;

  while ((pos = linha.find(espaco)) != std::string::npos) {
    palavras.push_back(linha.substr(0, pos));
    linha.erase(0, pos + 1);
  }

  std::string pontos = "...............";

  if (palavras[0].find(espaco)) {
    palavras[0] = palavras[0].substr(0, std::string::npos);
  }

  std::string novaLinha = palavras[0] + pontos;

  while (novaLinha.length() < 30) {
    novaLinha += ".";
  }
  std::cout << palavras[1] << std::endl;
  novaLinha += palavras[1];

  Botoes::Texto *texto = new Botoes::Texto(
      sf::Vector2f(640.f, 360.f), sf::Vector2f(30.f, 30.f), novaLinha, 50);
  texto->setTamanhoBorda(3.0f);
  texto->setColor(sf::Color::White);
  texto->setTextFont(CAMINHO_FONTE_RANKING);
  const int qtdVector = vectorTexto.size();
  texto->setPos(sf::Vector2f(310.f, 150.0f + 60.0f * qtdVector));
  vectorTexto.push_back(texto);
}
void MenuRanking::criarRanking() {
  std::ifstream arquivo(ARQUIVO_RANKING_TXT);

  if (!arquivo) {
    std::cout << "Erro em ler arquivo colocacao!" << std::endl;
    exit(1);
  }
  std::vector<std::string> nLinhas;
  std::string linha = "";
  while (std::getline(arquivo, linha)) {
    nLinhas.push_back(linha);
  }
  arquivo.close();

  for (int i = 0; i < (int)nLinhas.size(); i++) {
    criarTexto(nLinhas.at(i));
  }
}
void MenuRanking::desenharRanking() {
  for (int i = 0; i < (int)vectorTexto.size(); i++) {
    Botoes::Texto *texto = vectorTexto[i];
    pGrafico->drawText(texto->getSfTexto());
  }
}
void MenuRanking::inicializaBotao() {
  Botoes::Botao *pBotao = NULL;

  pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 720.f / 4 * 3),
                             std::string(" Voltar"));
  pBotao->selecionado(true);

  Menu::lBotao.push_back(pBotao);
  Menu::it = Menu::lBotao.begin();
}
void MenuRanking::executar() {
  switch (numSelec) {
  case 0: // voltar
    pMaquinaDeEstado->popEstado();
    break;
  default:
    break;
  }
}
void MenuRanking::update(const double dt) { Menu::update(dt); }
void MenuRanking::draw() {
  Menu::draw();

  pGrafico->drawText(titulo.getSfTexto());

  desenharRanking();
}
} // namespace Menu