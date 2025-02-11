#include "Menu.hpp"

#define TAM_TEXTO_RANKING_X 100.f
#define TAM_TEXTO_RANKING_Y 100.f
#define POS_TEXTO_RANKING_X 640.f
#define POS_TEXTO_RANKING_Y 100.f
#define CAMINHO_FONTE_RANKING "data/Font/menuRanking.ttf"
#define ARQUIVO_RANKING_TXT "data/Colocacao/colocacao.txt"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace Menu {
class MenuRanking : public Menu {
private:
  std::vector<Botoes::Texto *> vectorTexto;

public:
  MenuRanking();
  ~MenuRanking();
  void criarTexto(std::string linha);
  void criarRanking();
  void desenharRanking();
  void inicializaBotao();
  void executar();
  void update(const double dt);
  void draw();
};
} // namespace Menu