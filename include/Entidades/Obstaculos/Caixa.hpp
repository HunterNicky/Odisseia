#pragma once
#include "Obstaculo.hpp"
#include <vector>

#define TAM_PLATAFORMA_X 200.f
#define TAM_PLATAFORMA_Y 60.0f
#define CAMINHO_BLOCO_GRAMA "data/Sprites/blocos/grass.png"
#define CAMINHO_BLOCO_TERRA "data/Sprites/blocos/dirt.png"
#define CAMINHO_BLOCO_PEDRA "data/Sprites/blocos/cobblestone.png"
#define CAMINHO_BLOCO_PEDRA_R "data/Sprites/blocos/roadcobblestone.png"
#define CAMINHO_BLOCO_PEDRA_V "data/Sprites/blocos/woodplataformcobblestone.png"
#define CAMINHO_BLOCO_PORTAL "data/Sprites/blocos/buracoNegro.png"
#define CAMINHO_BLOCO_CAIXA "data/Sprites/blocos/caixa.png"

namespace Entidades {
namespace Obstaculos {
class Caixa : public Obstaculo {
private:
  bool PortalAtivo;
  int idTextura;
  std::string caminhoTextura;
  std::vector<std::string> texturas;
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  Caixa(const sf::Vector2f pos, const sf::Vector2f, const Entidades::ID id,
        const std::string path);
  Caixa(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Caixa();
  void animacao();
  void colocarTextura();
  const bool getPortalAtivo() const;
  void setPortalAtivo(const bool ativo);
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos

} // namespace Entidades