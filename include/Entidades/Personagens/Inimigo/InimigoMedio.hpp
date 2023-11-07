#include "Inimigo.hpp"

namespace Entidades{
    namespace Personagens{
        class InimigoMedio: public Inimigo{
        private:

        public:
            InimigoMedio();
            ~InimigoMedio();
            void operator--(const int dano);
            void movimentoAleatorio();
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
        };
    }
}