#pragma once

#include "Animacao/AnimacaoStrategy.hpp"
#include "AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoContext{
        private:
            AnimacaoStrategy* strategy;
            float standardTime;
        public:
            AnimacaoContext();
            ~AnimacaoContext();
            void setStrategy(AnimacaoStrategy* strategy, const float standardTime);
            void updateStrategy(const double dt);
    };

}