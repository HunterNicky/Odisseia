#pragma once

#include "..\..\src\Ente.cpp"

namespace Entidades{
    enum ID{
        empty = 0,
        jogador
    };

    class Entidade : public Ente{
        protected:
            ID id;
            sf::RectangleShape body;
        public:
            Entidade(sf::Vector2f pos, sf::Vector2f size, ID id);
            virtual ~Entidade();
            ID getId() const;
            const sf::RectangleShape getBody() const;
            virtual void update() = 0;
            virtual void exec() = 0;
            virtual void draw();
    };
}