#pragma once

#include "Fase.hpp"


namespace Estados{
    namespace Fases{
        class Fase2: public Fase{
        private:

        public:
            Fase2();
            ~Fase2();
            void newLava(sf::Vector2f pos, sf::Vector2f size);
            void recuperarJogada();
            void loadMap();
            void draw();
            void update();
            void executar();
        };
    }

}