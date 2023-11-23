#include "..\..\..\..\include\Entidades\Personagens\Inimigo\Samurai.hpp"
#include <sstream>

namespace Entidades{
    namespace Personagens{
        void Samurai::inicializa(){
            vel = sf::Vector2f(0.01f, 0.01f);
            num_vidas = 1000;
            body->setFillColor(sf::Color::Yellow);
        }

        Samurai::Samurai(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(pos, size, id, pJog){
            inicializa();
        }

        Samurai::Samurai(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Jogador* pJog):
            Inimigo(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]),sf::Vector2f(TAM_INIMIGO_DIF_X, TAM_INIMIGO_DIF_Y), id, pJog )
        {
            this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
            this->num_vidas = atributos[pos]["Vida"][0];
        }

        Samurai::~Samurai(){

        }
        void Samurai::operator--(const int dano){
            num_vidas-=dano;
        }
        void Samurai::movimentoAleatorio(){

        }
        void Samurai::move(){
            Entidade::body->setPosition(pos);
            gColisao->Notify(static_cast<Entidades::Entidade*>(this));
        }

        void Samurai::danificar(Entidade* entidade){
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(200);
        }

        void Samurai::tratarColisao(Entidade* entidade){
            if(entidade){
                if(entidade->getId() == Entidades::ID::jogador){
                    danificar(entidade);
                }
            }
        }
        void Samurai::executar(){
            move();
        }
        void Samurai::update(){
            executar();
        }

        void Samurai::salvar(std::ostringstream* entrada){
            (*entrada) << "{ \"ID\": [" << 4 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "], \"Vida\": [" << this->getNum_vidas() << "] }" << std::endl;
        }
    }
}