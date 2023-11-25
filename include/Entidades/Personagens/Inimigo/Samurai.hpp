#include "Animacao/AnimacaoAtaque.hpp"
#include "Inimigo.hpp"

#define TAM_INIMIGO_DIF_X 20.0f
#define TAM_INIMIGO_DIF_Y 32.0f
#define CAMINHO_SAMURAI_ANDAR "data\\Sprites\\samurai\\samuraiwalk.png"
#define CAMINHO_SAMURAI_PARADO "data\\Sprites\\samurai\\samuraiidle.png"
#define CAMINHO_SAMURAI_ATAQUE "data\\Sprites\\samurai\\samuraiatack.png"

#define R 20.f

namespace Entidades {
namespace Personagens {
class Samurai : public Inimigo {
private:
  Animacao::AnimacaoAndar andar;
  Animacao::AnimacaoParado parado;
  Animacao::AnimacaoAtaque atacando;
  Animacao::AnimacaoContext contextoAnimacao;
  void inicializa();

public:
  Samurai(const sf::Vector2f pos, const sf::Vector2f size,
          const Entidades::ID id, Entidades::Personagens::Jogador *pJog);
  Samurai(nlohmann::json atributos, const int pos, const Entidades::ID id,
          Entidades::Personagens::Jogador *pJog);
  ~Samurai();
  void animacao();
  void operator--(const int dano);
  void movimentoAleatorio();
  void move();
  void danificar(Entidade *entidade);
  void atacar();
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Personagens
} // namespace Entidades