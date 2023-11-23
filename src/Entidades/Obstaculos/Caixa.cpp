#include "..\..\..\include\Entidades\Obstaculos\Caixa.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Caixa.hpp"

namespace Entidades{
    namespace Obstaculos{
        ObstaculoFacil::ObstaculoFacil(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id) :
            Obstaculo(pos, size, id),
            bloco(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Obstaculo\\Grama.png", 6, sf::Vector2f(1,1)),
            contexto()
        {
            contexto.setStrategy(&bloco, 1.f);
            this->body->setFillColor(sf::Color::White);
        }

        ObstaculoFacil::ObstaculoFacil(nlohmann::json atributos, const int pos, const Entidades::ID id):
            Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_PLATAFORMA_X, TAM_PLATAFORMA_Y), id),
            bloco(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Obstaculo\\Grama.png", 6, sf::Vector2f(1,1)),
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
        void ObstaculoFacil::salvar(std::ostringstream* entrada){
             (*entrada) << "{ \"ID\": [" << 5 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "] }"<< std::endl;
        }
    }
}
