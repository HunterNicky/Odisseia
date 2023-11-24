#include "Entidades/Obstaculos/Caixa.hpp"

namespace Entidades{
    namespace Obstaculos{
        Caixa::Caixa(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, const std::string path) :
            Obstaculo(pos, size, id), PortalAtivo(false),
            bloco(static_cast<Entidades::Entidade*>(this), path, 1),
            contexto()
        {
            contexto.setStrategy(&bloco, 1.f);
            this->body->setFillColor(sf::Color::White);
        }

        Caixa::Caixa(nlohmann::json atributos, const int pos, const Entidades::ID id):
            Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_PLATAFORMA_X, TAM_PLATAFORMA_Y), id),
            bloco(static_cast<Entidades::Entidade*>(this), "data\\Sprites\\Obstaculo\\Grama.png", 6),
            contexto()
        {
            contexto.setStrategy(&bloco, 1.f);
            this->body->setFillColor(sf::Color::White);
        }
        Caixa::~Caixa(){}
        
        void Caixa::animacao(){
            contexto.updateStrategy(gFisico->getDeltaTime());
        }
        void Caixa::colocarTextura(const char c){
 
        }

        void Caixa::setPortalAtivo(const bool ativo){
            PortalAtivo = ativo;
        }
        const bool Caixa::getPortalAtivo() const{
            return PortalAtivo;
        }
        void Caixa::tratarColisao(Entidade* entidade){
            if(PortalAtivo){ //portal
                
            }
        }
        void Caixa::executar(){
            animacao();
        }
        void Caixa::update(){
            executar();
        }
        void Caixa::salvar(std::ostringstream* entrada){
             (*entrada) << "{ \"ID\": [" << 5 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "] }"<< std::endl;
        }
    }
}
