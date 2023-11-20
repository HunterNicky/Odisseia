#pragma once

#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

namespace Animacao {
    class AnimacaoStrategy{
        protected:
            static Gerenciadores::GerenciadorGrafico* pGrafico;
            Entidades::Entidade* entidade;
            sf::IntRect rectSize;
            sf::Texture* textura;
            int numFrames;
        public:
            AnimacaoStrategy(Entidades::Entidade* entidade, int numFrames);
            virtual ~AnimacaoStrategy();
            virtual void updateSprite(double dt, float standardTime);
            virtual void changeTexture() = 0;
    };
}