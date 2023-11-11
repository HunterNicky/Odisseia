#include "..\..\..\include\Menu\Botoes\Botao.hpp"

namespace Menu{
    namespace Botoes{
        Botao::Botao(const sf::Vector2f pos, std::string stdTexto):
            Ente(pos, sf::Vector2f(0, 0)), texto(pos, sf::Vector2f(100, 50), stdTexto, 30) {
            padraoT = new sf::Texture;
            selecionadoT = new sf::Texture;
            padraoT->loadFromFile("data/Botao/botao.png");
            selecionadoT->loadFromFile("data/Botao/botaoselect.png");

            texto.setColor(sf::Color::White);

            body = new sf::RectangleShape(sf::Vector2f(100, 50));
            body->setPosition(pos);
            body->setTexture(padraoT);
        }
        
        Botao::~Botao(){
            delete body;
        }

        void Botao::selecionado(const bool select){
            if (select){
                body->setTexture(selecionadoT);
            } else{
                body->setTexture(padraoT);
            }
        }

        void Botao::draw(){
            pGrafico->draw(body);
        }
        void Botao::update(){
        }
        void Botao::executar()
        {
        }
    }
}
