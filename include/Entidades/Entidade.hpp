#pragma once
#include "..\Ente.hpp"
namespace Entidades{
    enum ID{
        empty = 0,
        jogador,
        Inimigo,
        ObstaculoFacil
    };

    class Entidade : public Ente{
        protected:
            int id;
            sf::RectangleShape* body;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f size, const ID id);
            virtual ~Entidade();
            const int getId() const;
            void setBody(sf::RectangleShape* body);
            sf::RectangleShape* getBody();
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void draw();
    };
}