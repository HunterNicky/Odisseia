#include "..\..\..\include\Entidades\Obstaculos\Caixa.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"

namespace Entidades{
    namespace Obstaculos{
        ObstaculoFacil::ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id) :
            Obstaculo(pos, size, id),
            bloco(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Obstaculo\\Grama.png", 6),
            contexto()
        {
            contexto.setStrategy(&bloco, 1.f);
            this->body->setFillColor(sf::Color::White);
        }
        ObstaculoFacil::~ObstaculoFacil(){

        }
        void ObstaculoFacil::tratarColisao(Entidade* entidade){

        }
        void ObstaculoFacil::executar(){
            contexto.updateStrategy(gFisico->getDeltaTime());
        }
        void ObstaculoFacil::update(){
            executar();
        }
    }
}
