#include "..\..\..\include\Menu\Botoes\Texto.hpp"

namespace Menu{
    namespace Botoes{
        Texto::Texto(const sf::Vector2f pos, const sf::Vector2f size, const std::string texto, unsigned int sizeFont)
            :fonte(), texto(texto), pos(pos), size(size), color(sf::Color::White), sizeFont(sizeFont){
            fonte.loadFromFile("data/Font/MANBORT.otf");
            sfTexto.setFont(fonte);
            sfTexto.setString(texto);
            sfTexto.setCharacterSize(sizeFont);
            sfTexto.setPosition(pos);
            sfTexto.setColor(color);
        }

        Texto::~Texto(){}

        void Texto::setTexto(std::string texto){
            this->texto = texto;
            sfTexto.setString(texto);
        }

        void Texto::setPos(const sf::Vector2f pos){
            this->pos = pos;
            sfTexto.setPosition(pos);
        }

        void Texto::setSize(const sf::Vector2f size){
            this->size = size;
        }

        void Texto::setColor(const sf::Color color){
            this->color = color;
            sfTexto.setColor(color);
        }

        const sf::Vector2f Texto::getPos() const{
            return pos;
        }

        const sf::Vector2f Texto::getSize() const{
            return size;
        }

        const sf::Text Texto::getSfTexto() const{
            return sfTexto;
        }

        const std::string Texto::getText() const{
            return texto;
        }

        void Texto::setFontSize(unsigned int sizeFont){
            this->sizeFont = sizeFont;
            sfTexto.setCharacterSize(sizeFont);
        }
    }
}
