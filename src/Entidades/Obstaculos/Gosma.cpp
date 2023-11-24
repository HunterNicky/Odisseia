#include "..\..\..\include\Entidades\Obstaculos\Gosma.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Gosma.hpp"

namespace Entidades{
    namespace Obstaculos{
        float Gosma::slow = 0.5;

        Gosma::Gosma(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Obstaculo(pos, size, id), bloco(static_cast<Entidades::Entidade*>(this), CAMINHO_BLOCO_GOSMA, 10), contexto(){
            this->body->setFillColor(sf::Color::Green);
            contexto.setStrategy(&bloco, 0.1f);
        }
        Gosma::~Gosma(){}

        void Gosma::animacao(){
            contexto.updateStrategy(gFisico->getDeltaTime());
        }

        void Gosma::atrasar(Entidade* entidade){
            sf::Vector2f vel = entidade->getVel()*slow;
            entidade->setVel(vel);
        }

        void Gosma::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    atrasar(entidade);
                }
            }
        }
        
        void Gosma::executar(){
            animacao();
        }
        void Gosma::update(){
            executar();
        }

        void Gosma::salvar(std::ostringstream* entrada){
             (*entrada) << "{ \"ID\": [" << 5 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "] }" << std::endl;
        }
    }
}