#pragma once
#include "..\Ente.hpp"
using namespace std;

namespace Entidades{
    /*
    enum ID{
        empty = 0,
        jogador
    };
    */
    class Entidade : public Ente{
        protected:
            int id;
            sf::RectangleShape body;
        public:
            Entidade(sf::Vector2f pos, sf::Vector2f size, int id);
            virtual ~Entidade();
            const int getId() const;
            void setBody(sf::RectangleShape body);
            sf::RectangleShape getBody();
            virtual void executar() = 0;
            virtual void draw();
    };
}