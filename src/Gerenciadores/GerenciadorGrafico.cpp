#include "..\..\include\Gerenciadores\GerenciadorGrafico.hpp"

namespace Gerenciadores{
    GerenciadorGrafico* GerenciadorGrafico::instance = nullptr;

    GerenciadorGrafico* GerenciadorGrafico::getInstance(){
        if(instance == nullptr){
            instance = new GerenciadorGrafico();
        }
        return instance;
    }

    GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(1280,720),"Minion++")),
    view(/*sf::Vector2f(1280/2,720/2)*/sf::Vector2f(0.f,0.f), sf::Vector2f(1280,720)){}

    GerenciadorGrafico::~GerenciadorGrafico(){}

    void GerenciadorGrafico::display(){
        if(isWindowOpen()){
            window->setView(view);
            window->display();
        }
    }

    void GerenciadorGrafico::clear(){
        if(isWindowOpen()){
            window->clear();
        }
    }

    void GerenciadorGrafico::close(){
        if(isWindowOpen()){
            window->close();
        }
    }

    void GerenciadorGrafico::draw(const sf::Drawable* drawable){
        if(isWindowOpen()){
            window->draw(*drawable);
        }
    }

    const bool GerenciadorGrafico::isWindowOpen(){
        return window->isOpen();
    }

    const bool GerenciadorGrafico::pollEvent(sf::Event &event){
        return window->pollEvent(event);
    }

    void GerenciadorGrafico::setViewCenter(sf::Vector2f center){
        if(isWindowOpen()){
            view.setCenter(sf::Vector2f(center));
        }
    }
}

