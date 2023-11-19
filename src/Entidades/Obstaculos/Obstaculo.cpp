#include "..\..\..\include\Entidades\Obstaculos\Obstaculo.hpp"
namespace Entidades{
    namespace Obstaculos{
        Gerenciadores::GerenciadorFisico* Obstaculo::gFisico = Gerenciadores::GerenciadorFisico::getInstance();


        Obstaculo::Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const Entidades::ID id) :
            Entidade(pos, size, id)
        {

        }

        Obstaculo::~Obstaculo(){
            
        }

        void Obstaculo::verificaSolo(sf::Vector2f mtv){
        }
    }
}