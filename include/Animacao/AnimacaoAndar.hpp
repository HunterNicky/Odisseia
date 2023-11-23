#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoAndar : public AnimacaoStrategy{
        private:
            sf::Texture* run;
            const int numFrameWalk;
            const int numFrameRun;
            const sf::Vector2f escalaRun;
            float actualFrame;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateSpriteRect();
            void updateRun(); 
            void changeTexture(sf::Texture* corrida);
        public:
          AnimacaoAndar(Entidades::Entidade *entidade, std::string path,
                        std::string path2, const int numFrameWalk,
                        const int numFrameRun, const sf::Vector2f escalaRun, const sf::Vector2f escalaWalk);
          ~AnimacaoAndar();
          void updateSprite(double dt, float standardTime);
          void changeTexture();
    };
}