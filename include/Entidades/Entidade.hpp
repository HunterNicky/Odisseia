#pragma once

#include "..\Ente.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Gerenciadores{
    class GerenciadorDeColisao; 
    class GerenciadorFisico;
}

namespace Entidades{
    enum class ID{
        empty = 0,
        jogador,
        Inimigo,
        Plataforma,
        Caixa, 
        Gosma,
        Lava,
        Projetil
    };

    class Entidade : public Ente{
        protected:
            int id;
            sf::RectangleShape* body;
            static Gerenciadores::GerenciadorDeColisao* gColisao;
            static Gerenciadores::GerenciadorFisico* gFisico;
            const Entidades::ID ID;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            virtual ~Entidade();
            const Entidades::ID getId() const;
            void setBody(sf::RectangleShape* body);
            void setGerenciadorDeColisao(Gerenciadores::GerenciadorDeColisao* gColisao);
            sf::RectangleShape* getBody();
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void verificaSolo(const sf::Vector2f mtv) = 0;
            virtual void salvar(std::ostringstream* entrada);
            virtual void draw();      
    };
}