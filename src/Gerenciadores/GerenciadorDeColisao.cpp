#include "..\..\include\Gerenciadores\GerenciadorDeColisao.hpp"
#include <iostream>

namespace Gerenciadores{
    GerenciadorDeColisao::GerenciadorDeColisao(){}
    GerenciadorDeColisao::~GerenciadorDeColisao(){}
    void GerenciadorDeColisao::setList(Lista::ListaDeEntidades* LE){this->LE = LE;}

    void GerenciadorDeColisao::Notify(Entidades::Entidade* entidade, Entidades::Entidade* entidade2 ,const sf::Vector2f mtv) const{
        entidade->getBody()->move(mtv);
        entidade->tratarColisao(entidade2);
    }

    bool GerenciadorDeColisao::collisionDetection(const sf::Drawable *drawable1, const sf::Drawable *drawable2, sf::Vector2f *mtv){
        const sf::FloatRect &rs1 = static_cast<const sf::RectangleShape&>(*drawable1).getGlobalBounds();
        const sf::FloatRect &rs2 = static_cast<const sf::RectangleShape&>(*drawable2).getGlobalBounds();
        sf::Vector2f projection;
        sf::Vector2f overlap;

        projection.x = std::max(rs1.left + rs1.width, rs2.left + rs2.width) - std::min(rs1.left, rs2.left);
        if (projection.x < (rs1.width + rs2.width)) {
            overlap.x = (rs1.width + rs2.width) - projection.x;
            projection.y = std::max(rs1.top + rs1.height, rs2.top + rs2.height) - std::min(rs1.top, rs2.top);

            if (projection.y < (rs1.height + rs2.height)) {
                overlap.y = rs1.height + rs2.height - projection.y;
                mtv->x = mtv->y = 0;
                if (overlap.x - overlap.y < -0.5f) {
                    mtv->x = overlap.x * (rs1.left < rs2.left ? -1 : 1);
                } else {
                    mtv->y = overlap.y * (rs1.top < rs2.top ? -1 : 1);
                }
                return true;
            }
        }
        return false;
    }

    void GerenciadorDeColisao::checkCollision(Entidades::Entidade* entidade){
        Lista::ListaDeEntidades* listaEntidades = LE;

        for(unsigned int i = 0; i < listaEntidades->getSize(); i++){
            Entidades::Entidade* entidade2 = (*listaEntidades)[i];
            if(entidade != entidade2){
                sf::Vector2f mtv;
                if(collisionDetection(entidade->getBody(), entidade2->getBody(), &mtv)){
                    Notify(entidade, entidade2, mtv);
                }
            }
        }
    }
}