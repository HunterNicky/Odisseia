#pragma once
#include "..\Ente.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
namespace Gerenciadores{
    class GerenciadorDeColisao; 
}
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
            sf::RectangleShape* body;
            Gerenciadores::GerenciadorDeColisao* gColisao;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f size, const int id);
            virtual ~Entidade();
            const int getId() const;
            void setBody(sf::RectangleShape* body);
            void setGerenciadorDeColisao(Gerenciadores::GerenciadorDeColisao* gColisao);
            sf::RectangleShape* getBody();
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void draw();
    };
}