#pragma once

#include "Animacao/AnimacaoStrategy.hpp"
#include "Entidades/Personagens/Personagem.hpp"

namespace Animacao {
    class AnimacaoParado : public AnimacaoStrategy{
        private:
            float actualFrame;
            float deepBreath;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateSpriteRect();
        public:
            AnimacaoParado(Entidades::Entidade* entidade ,std::string path, int numFrames, sf::Vector2f escala);
            ~AnimacaoParado();
            void updateSprite(double dt, float standardTime);
            void changeTexture();
    };
}