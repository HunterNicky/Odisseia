#include "..\..\..\include\Estados\Fases\Fase.hpp"
#include "Entidades/Entidade.hpp"

namespace Estados{
    namespace Fases{
        Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
        Gerenciadores::GerenciadorDeEvento* Fase::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
        Gerenciadores::GerenciadorFisico* Fase::pFisico = Gerenciadores::GerenciadorFisico::getInstance();
        Gerenciadores::GerenciadorDeColisao* Fase::pColisao = Gerenciadores::GerenciadorDeColisao::getInstance();
        Estados::MaquinaDeEstado* Fase::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

        Fase::Fase():
        Estado(pMaquinaDeEstado, 1){
            pJogador = nullptr;
            controle = new Observadores::ControleJogador(pJogador);
            pColisao->setList(&LE);
            pEvento->addObserver(static_cast<Observadores::Observer*>(controle));
            dt = 0.f, alpha = 0.f;
        }
        Fase::~Fase(){
            for(unsigned int i = 0; i < LE.getSize(); i++){
                LE.remove(i);
            }
            LE.clear();
            pEvento->removeObserver(static_cast<Observadores::Observer*>(controle));
        }
        void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
            pJogador = new Entidades::Personagens::Jogador(pos, size, 1);
            pJogador->setGerenciadorDeColisao(pColisao);
            controle->setJogador(pJogador);
            LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
        }
        void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, size, 2, pJogador);
            pInimigo->setGerenciadorDeColisao(pColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, 3);
            pObstaculoFacil->setGerenciadorDeColisao(pColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
        }
        void Fase::update(double dt, double alpha){
            this->dt = dt;
            this->alpha = alpha;
            executar();
        }
        void Fase::executar(){
            if(pJogador){
                sf::Vector2f cameraPos = pGrafico->getViewCenter();
                sf::Vector2f jogadorPos = pJogador->getBody()->getPosition();
                sf::Vector2f novaPosCamera = cameraPos + (jogadorPos - cameraPos) * 0.01f;
                novaPosCamera.y = 9*200;
                pGrafico->setViewCenter(novaPosCamera);
                pEvento->stage();
                pFisico->update(dt, alpha);
                LE.updateAll();
            }
        }
        void Fase::draw(){
            LE.drawAll();
        }
    }
}
