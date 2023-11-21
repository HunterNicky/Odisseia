#include "..\..\..\include\Entidades\Projetil\Projetil.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Projetil/Projetil.hpp"

namespace Entidades{
    //Dano do projetil
    int Projetil::dano(100);

    Projetil::Projetil(const sf::Vector2f pos, const Entidades::ID id, const bool direita):
        Entidade(pos, sf::Vector2f(10.0f, 10.0f), id)
    {
        if(direita){
            vel = sf::Vector2f(10.0f, 1.0f);
        }else{
            vel = sf::Vector2f(-10.0f, 1.0f);
        }
        body->setFillColor(sf::Color::Green);
    }

    Projetil::Projetil(nlohmann::json atributos, const int pos, const Entidades::ID id): 
        Entidade(sf::Vector2f(atributos[pos]["Posicao"][0], atributos[pos]["Posicao"][1]), sf::Vector2f(10.0f, 10.0f), id){

        body->setFillColor(sf::Color::Green);
        this->setVel(sf::Vector2f(atributos[pos]["Velocidade"][0], atributos[pos]["Velocidade"][1]));
    }

    Projetil::~Projetil(){

    }

    void Projetil::tratarColisao(Entidades::Entidade* entidade){
        if(entidade->getId() == Entidades::ID::jogador){
            std::cout << "Projetil colidiu com jogador!" << std::endl;
            Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(entidade);
            pPers->operator--(dano);
            //pinim->deletarProjetil();
        }
        else if(entidade->getId() == Entidades::ID::Plataforma){
            //pinim->deletarProjetil();
        }
    }

    void Projetil::verificaSolo(const sf::Vector2f mtv){
        if(mtv.y < 0.f){
            onFloor = true;
         }else{onFloor = false;} 
    }

    void Projetil::move(){
        this->setVel(sf::Vector2f(1.f, -50.f));
        body->move(vel);
    }

    void Projetil::draw(){
        pGrafico->draw(body);
    }

    void Projetil::executar(){
        move();
        Entidade::body->setPosition(pos);
        gColisao->Notify(static_cast<Entidades::Entidade*>(this));
    }

    void Projetil::update(){
        executar();
    }
    void Projetil::salvar(std::ostringstream* entrada){
         (*entrada) << "{ \"ID\": [" << 9 << "], \"Posicao\": [" << pos.x << " , " << pos.y << "], \"Velocidade\": [" << vel.x << " , " << vel.y << "] }" << std::endl;
    }
}