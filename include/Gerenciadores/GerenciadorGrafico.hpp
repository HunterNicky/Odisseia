#pragma once

#include <SFML/Graphics.hpp>

namespace Gerenciadores{
    class GerenciadorGrafico{
        private:
            sf::RenderWindow* window;
            sf::View view;
            static GerenciadorGrafico* instance;
            std::map<std::string, sf::Texture*> texturaMap;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getInstance();
            void display();
            void clear();
            void close();
            const bool isWindowOpen() const;
            const bool pollEvent(sf::Event &event);
            void draw(const sf::Drawable *drawable);
            void drawText(const sf::Text *text);
            void setViewCenter(const sf::Vector2f center);
            const sf::Vector2f getViewCenter() const;
            sf::Texture* loadTexture(std::string filepath);
    };
}