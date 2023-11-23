#include "Entidades/Projetil/Laser.hpp"
#include "Entidades/Personagens/Inimigo/Viajante.hpp"


namespace Entidades{
    //Dano do projetil
    int Laser::dano(100);

    Laser::Laser(const sf::Vector2f pos, const Entidades::ID id, Entidades::Personagens::Viajante* pInim):
        Entidade(pos, sf::Vector2f(TAM_PROJETIL,TAM_PROJETIL), id), pInim(pInim)
    {
        body->setFillColor(sf::Color::Green);
        setPos(sf::Vector2f(-300.f, -300.f));
        if(pInim){
            if(pInim->getDirecaoProj()){
                setVel(sf::Vector2f(100.f, -1.f));
            }else{
                setVel(sf::Vector2f(-100.f, -1.f));
            }
        }
    }

    Laser::Laser(nlohmann::json atributos, const int pos, const Entidades::ID id, Entidades::Personagens::Viajante* pInim): 
        Entidade(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]), sf::Vector2f(TAM_PROJETIL,TAM_PROJETIL), id), pInim(pInim){
        body->setFillColor(sf::Color::Green);
        this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
    }

    Laser::~Laser(){

    }

    void Laser::tratarColisao(Entidades::Entidade* entidade){
        if(entidade->getId() == Entidades::ID::jogador){
            std::cout << "Laser colidiu com jogador!" << std::endl;
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(dano);
            setPos(sf::Vector2f(-1000.f, -1000.f));
        }
        else if(entidade->getId() == Entidades::ID::Plataforma){
            //pInim->deletarProjetil();
            setPos(sf::Vector2f(-1000.f, -1000.f));
        }
    }

    void Laser::verificaSolo(const sf::Vector2f mtv){
        if(mtv.y < 0.f){
            onFloor = true;
         }else{onFloor = false;} 
    }

    void Laser::move(){
        if(pInim->getDirecaoProj()){
            setVel(sf::Vector2f(-100.f, -1.f));
        }else{
            setVel(sf::Vector2f(100.f,-1.f));
        }
        body->move(vel);
    }

    void Laser::draw(){
        pGrafico->draw(body);
    }

    void Laser::executar(){
        move();
        Entidade::body->setPosition(pos);
        gColisao->Notify(static_cast<Entidades::Entidade*>(this));
    }

    void Laser::update(){
        executar();
    }
    void Laser::salvar(std::ostringstream* entrada){
         (*entrada) << "{ \"ID\": [" << 9 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "] }" << std::endl;
    }
}