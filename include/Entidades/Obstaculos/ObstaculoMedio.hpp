#include "Obstaculo.hpp"

namespace Entidades{
    namespace Obstaculos{
        class ObstaculoMedio : public Obstaculo{
        private:
            int dano;
        public:
            ObstaculoMedio(const sf::Vector2f pos, const sf::Vector2f size, const int id);
            ~ObstaculoMedio();
            void executar();
            void update();
        };
    }
}