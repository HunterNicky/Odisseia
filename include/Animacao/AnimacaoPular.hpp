#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoPular : public AnimacaoStrategy{
        private:
            sf::Texture* HighJump;
            const int numFrameHighJump;
            const int numFrameLowJump;
            const sf::Vector2f escalaLowJump;
            float actualFrame;
            float jumpTime;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateJump(double dt);
            void updateSpriteRect();
            void changeTexture(sf::Texture* pulo);
        public:
          AnimacaoPular(Entidades::Entidade *entidade, std::string path,
                        std::string path2, const int numFrameLowJump,
                        const int numFrameHighJump,
                        const sf::Vector2f escalaLowJump,
                        const sf::Vector2f escalaHighJump);
          ~AnimacaoPular();
          void updateSprite(double dt, float standardTime);
          void changeTexture();
    };
}