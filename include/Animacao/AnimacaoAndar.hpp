#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoAndar : public AnimacaoStrategy{
        private:
            sf::Texture* run;
            const int numFrameWalk;
            const int numFrameRun;
            float actualFrame;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateSpriteRect();
            void updateRun(); 
            void changeTexture(sf::Texture* corrida);
        public:
            AnimacaoAndar(Entidades::Entidade* entidade ,std::string path, std::string path2, const int numFrameWalk, const int numFrameRun);
            ~AnimacaoAndar();
            void updateSprite(double dt, float standardTime);
            void changeTexture();
    };
}