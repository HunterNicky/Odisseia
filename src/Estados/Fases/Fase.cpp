#include "..\..\..\include\Estados\Fases\Fase.hpp"


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
            pJogador = new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
            pJogador->setGerenciadorDeColisao(&gerenciadorDeColisao);
            controle->setJogador(pJogador);
            LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
        }
        void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::InimigoFacil* pInimigo = new Entidades::Personagens::InimigoFacil(pos, size, Entidades::ID::Inimigo, pJogador);
            pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        void Fase::newInimigoMedio(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::InimigoMedio* pInimigo = new Entidades::Personagens::InimigoMedio(pos, size, Entidades::ID::Inimigo, pJogador, this);
            pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        void Fase::newChefao(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Personagens::InimigoDificil* pInimigo = new Entidades::Personagens::InimigoDificil(pos, size, Entidades::ID::Inimigo, pJogador);
            pInimigo->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
        }
        
        void Fase::newProjetil(sf::Vector2f pos, const bool direita){
            Entidades::Projetil* pProj = new Entidades::Projetil(pos, Entidades::ID::Projetil, direita);
            pProj->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pProj));
        }
        
        void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, Entidades::ID::Plataforma);
            pObstaculoFacil->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
        }
        void Fase::update(double dt, double alpha){
            this->dt = dt;
            this->alpha = alpha;
            executar();
        }

        void Fase::newLava(sf::Vector2f pos, sf::Vector2f size){
            Entidades::Obstaculos::Lava* pLava = new Entidades::Obstaculos::Lava(pos, size, Entidades::ID::Lava);
            pLava->setGerenciadorDeColisao(&gerenciadorDeColisao);
            LE.push_back(static_cast<Entidades::Entidade*>(pLava));
        }

        void Fase::updateVida(){
            for(unsigned int i = 0; i < LE.getSize(); i++){
                if((LE[i]->getId() == Entidades::ID::Inimigo) || (LE[i]->getId() == Entidades::ID::jogador)){
                    Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(LE[i]);
                    if(pPers->getNum_vidas() < 0)
                        LE.remove(i);
                }
            }
        }

        void Fase::executar(){
            if(pJogador){
                pGrafico->setViewCenter(pJogador->getBody()->getPosition());
                pEvento->stage();
                pFisico->update(dt, alpha);
                LE.updateAll();
                pFisico->update(dt, alpha);
                pGrafico->display();
                pGrafico->clear();
            }
        }
        void Fase::draw(){
            LE.drawAll();
        }
    }
}
