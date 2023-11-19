#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoCorrida : public AnimacaoStrategy{
        private:
            float actualFrame;
            float deepBreath;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateSpriteRect();
        public:
            AnimacaoCorrida(Entidades::Entidade* entidade ,std::string path, int numFrames);
            ~AnimacaoCorrida();
            void updateSprite(double dt, float standardTime);
            void changeTexture();
    };
}