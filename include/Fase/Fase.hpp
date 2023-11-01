#include "..\Ente.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Entidades\Obstaculos\ObstaculoFacil.hpp"


namespace Fase{
    class Fase : public Ente{
    protected:
        Lista::ListaDeEntidades listaPersonagens;
        Gerenciadores::GerenciadorDeColisao* pGrafico;
    public: 
        Fase();
        ~Fase();
        void createInimigo(const sf::Vector2f pos);
        void createJogador(const sf::Vector2f pos);
        void createPlataforma(const sf::Vector2f pos);
        void createBox(const sf::Vector2f pos);
        void draw();
        void executar();
        void update();
    };
}