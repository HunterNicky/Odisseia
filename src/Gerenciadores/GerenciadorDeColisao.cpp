#include "..\..\include\Gerenciadores\GerenciadorDeColisao.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/QuadTree.hpp"
#include <iostream>

namespace Gerenciadores{
    GerenciadorDeColisao* GerenciadorDeColisao::instance = nullptr;

    GerenciadorDeColisao::GerenciadorDeColisao():
    quadTree(sf::FloatRect(sf::Vector2f(0.f,0.f), sf::Vector2f(10000.f, 10000.f)), 0){}
    GerenciadorDeColisao::~GerenciadorDeColisao(){
        delete(instance);
    }

    void GerenciadorDeColisao::setList(Lista::ListaDeEntidades* LE){
        this->LE = LE;
        for(unsigned int i = 0; i < this->LE->getSize(); i++){
            quadTree.insert(this->LE->operator[](i));
        }
    }

    GerenciadorDeColisao* GerenciadorDeColisao::getInstance(){
        if(instance == nullptr){
            instance = new GerenciadorDeColisao();
        }
        return instance;
    }

    void GerenciadorDeColisao::Notify(Entidades::Entidade* entidade, Entidades::Entidade* entidade2 ,const sf::Vector2f mtv) const{  
        entidade->setPos(sf::Vector2f(entidade->getPos().x + mtv.x, entidade->getPos().y + mtv.y));
        entidade->verificaSolo(mtv);
        entidade->tratarColisao(entidade2);
        //entidade2->tratarColisao(entidade);
    }

    void GerenciadorDeColisao::atualizarQuadTree(){
        quadTree.clear();
        for (unsigned int i = 0; i < this->LE->getSize(); i++){
            quadTree.insert(this->LE->operator[](i));
        }
    }
    
    void GerenciadorDeColisao::checkCollision(Entidades::Entidade *entidade){
        atualizarQuadTree();
        sf::Vector2f mtv;
        sf::FloatRect collisionRect;
        if(quadTree.detectCollision(entidade, collisionRect, mtv)){
            Notify(entidade, entidade, mtv);
        }
    }
}