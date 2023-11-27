#pragma once
#include "Obstaculo.hpp"

#define TAM_PLATAFORMA_X 200.f
#define TAM_PLATAFORMA_Y 60.0f
#define CAMINHO_BLOCO_GRAMA "data/Sprites/blocos/grass.png"
#define CAMINHO_BLOCO_TERRA "data/Sprites/blocos/dirt.png"
#define CAMINHO_BLOCO_PEDRA "data/Sprites/blocos/cobblestone.png"
#define CAMINHO_BLOCO_PEDRA_R "data/Sprites/blocos/roadcobblestone.png"
#define CAMINHO_BLOCO_PEDRA_V "data/Sprites/blocos/woodplataformcobblestone.png"

namespace Entidades {
namespace Obstaculos {
class Plataforma : public Obstaculo {
private:
  int idTextura;
  Animacao::AnimacaoBloco bloco;
  Animacao::AnimacaoContext contexto;

public:
  Plataforma(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id,
        const std::string path);
  Plataforma(nlohmann::json atributos, const int pos, const Entidades::ID id);
  ~Plataforma();
  void animacao();
  std::string colocarTextura(int idText);
  int setarIdTextura(const std::string path);
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos

} // namespace Entidades