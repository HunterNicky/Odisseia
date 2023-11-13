#include "..\..\..\include\Estados\Fases\Fase.hpp"
#include "Entidades/Entidade.hpp"

namespace Estados{
    namespace Fases{
        Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
        Gerenciadores::GerenciadorDeEvento* Fase::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
        Gerenciadores::GerenciadorFisico* Fase::pFisico = Gerenciadores::GerenciadorFisico::getInstance();
        Estados::MaquinaDeEstado* Fase::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

        Fase::Fase():
        Estado(pMaquinaDeEstado, 1){
            pJogador = nullptr;
            controle = new Observadores::ControleJogador(pJogador);
            gerenciadorDeColisao.setList(&LE);
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
            pJogador->setGerenciadorDeColisao(&gerenciadorDeColisao);
            controle->setJogador(pJogador);
            LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
        }
        void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::Inimigo* pInimigo = new Entidades::Personagens::Inimigo(pos, size, 2, pJogador);
            pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, 3);
            pObstaculoFacil->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
        }
        void Fase::update(double dt, double alpha){
            this->dt = dt;
            this->alpha = alpha;
            executar();
        }
        void Fase::executar(){
            if(pJogador){
                pGrafico->setViewCenter(pJogador->getBody()->getPosition());
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
