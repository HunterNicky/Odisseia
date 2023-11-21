#include "Fases/Fase.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Inimigo/InimigoMedio.hpp"
#include "Menu/Botoes/Texto.hpp"
#include "Observadores/ControleJogador.hpp"

#include <list>

namespace Fases{
    Gerenciadores::GerenciadorGrafico* Fase::pGrafico = Gerenciadores::GerenciadorGrafico::getInstance();
    Gerenciadores::GerenciadorDeEvento* Fase::pEvento = Gerenciadores::GerenciadorDeEvento::getInstance();
    Gerenciadores::GerenciadorFisico* Fase::pFisico = Gerenciadores::GerenciadorFisico::getInstance();
    Gerenciadores::GerenciadorDeColisao* Fase::pColisao = Gerenciadores::GerenciadorDeColisao::getInstance();
    Estados::MaquinaDeEstado* Fase::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();
    Menu::Botoes::Texto Fase::textoPontuacao(sf::Vector2f(0.f, 0.f), sf::Vector2f(50.f,50.f), "" , 35);

    Fase::Fase():
    Estado(pMaquinaDeEstado, 1){
        pJogador = nullptr;
        //controleFase = new Observadores::ControleFase();
        //controleFase->setFase(this);
        controleJog = new Observadores::ControleJogador(pJogador, static_cast<Fases::Fase*>(this));
        pColisao->setList(&LE);
        pEvento->addObserver(static_cast<Observadores::Observer*>(controleJog));
        dt = 0.f;
        pontuacao_jogador = 0;
        textoPontuacao.setColor(sf::Color::White);
        if(textoPontuacao.getText() == ""){
            textoPontuacao.setTexto("Score: 00000");
            textoPontuacao.setTamanhoBorda(2.f);
        }
        
    }
    Fase::~Fase(){
        salvar();
        for(unsigned int i = 0; i < LE.getSize(); i++){
            LE.remove(i);
        }
        LE.clear();
        pEvento->removeObserver(static_cast<Observadores::Observer*>(controleJog));

        if(pontuacao_jogador > 0){
            pontuacao_jogador = 0;
        }
    }

    void Fase::salvar(){
        std::ofstream arquivo(ARQUIVO_ENTIDADES);
        if(!arquivo){
            std::cout << "Erro ao abrir arquivo" << std::endl;
            exit(1);
        } 
        //salvar Personagens
        //Lista::Lista<Entidades::Entidade>::Iterator it = LE.getPrimeiro();
        buffer.str("");
        buffer << "[";

        if(LE[0] != nullptr){
            LE[0]->salvar(&buffer);
        }
        for(unsigned int i = 1; i < LE.getSize(); i++){
            buffer << ",";
            LE[i]->salvar(&buffer);
        }

        buffer << "]";
        arquivo << buffer.str() << std::endl;
        arquivo.close();
    }

    void Fase::newJogador(sf::Vector2f pos, sf::Vector2f size){
        pJogador = new Entidades::Personagens::Jogador(pos, size, Entidades::ID::jogador);
        pJogador->setGerenciadorDeColisao(pColisao);
        controleJog->setJogador(pJogador);
        LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
    }
    void Fase::newInimigo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::InimigoFacil* pInimigo = new Entidades::Personagens::InimigoFacil(pos, size, Entidades::ID::InimigoFacil, pJogador);
        pInimigo->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newInimigoMedio(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::InimigoMedio* pInimigo = new Entidades::Personagens::InimigoMedio(pos, size, Entidades::ID::InimigoMedio, pJogador, static_cast<Fases::Fase*>(this));
        pInimigo->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    void Fase::newChefao(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Personagens::InimigoDificil* pInimigo = new Entidades::Personagens::InimigoDificil(pos, size, Entidades::ID::InimigoDificil, pJogador);
        pInimigo->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
    }
    
    void Fase::newProjetil(sf::Vector2f pos, const bool direita){
        Entidades::Projetil* pProj = new Entidades::Projetil(pos, Entidades::ID::Projetil, direita);
        pProj->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pProj));
    }

    void Fase::deleteProjetil(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            if(LE[i]->getId() == Entidades::ID::Projetil){
                LE.remove(i);
            }
        }
    }
    
    void Fase::newObstaculo(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::ObstaculoFacil* pObstaculoFacil = new Entidades::Obstaculos::ObstaculoFacil(pos, size, Entidades::ID::Plataforma);
        pObstaculoFacil->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pObstaculoFacil));
    }
     
    void Fase::setPontuacaoJog(const unsigned int pontos){
        this->pontuacao_jogador = pontos;
        std::string score = std::to_string(this->pontuacao_jogador);
        while(score.size() < 5){
            std::string aux = score;
            score = '0' + aux;
        }
        textoPontuacao.setTexto("Score: " + score);
    }
    const unsigned int Fase::getPontuacaoJog(){
        return pontuacao_jogador;
    }

    void Fase::atualizaPontuacao(){
        sf::Vector2f posFundo = pGrafico->getViewCenter();
        sf::Vector2f tamJan = sf::Vector2f(1280.f, 720.f);
        textoPontuacao.setPos(sf::Vector2f(posFundo.x - tamJan.x/2, posFundo.y - tamJan.y/2));
        pGrafico->drawText(textoPontuacao.getSfTexto());
    }

    void Fase::update(double dt){
        this->dt = dt;
        executar();
    }

    void Fase::updateVida(){
        for(unsigned int i = 0; i < LE.getSize(); i++){
            if(LE[i]->getId() == Entidades::ID::InimigoFacil){
                Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(LE[i]);
                if(pPers->getNum_vidas() < 0){
                    setPontuacaoJog(getPontuacaoJog()+200);
                    LE.remove(i);
                }
                   
            }
            if(LE[i]->getId() == Entidades::ID::jogador){
                //remover Jogador
                Entidades::Personagens::Personagem* pPers = static_cast<Entidades::Personagens::Personagem*>(LE[i]);
                if(pPers->getNum_vidas() < 0){
                    controleJog->jogadorNeutralizado();
                    LE.remove(i);
                }
            }
        }
    }

    void Fase::executar(){
        if(pJogador){
            sf::Vector2f cameraPos = pGrafico->getViewCenter();
            sf::Vector2f jogadorPos = pJogador->getBody()->getPosition();
            sf::Vector2f novaPosCamera = cameraPos + (jogadorPos - cameraPos) * 0.01f;
            pGrafico->setViewCenter(novaPosCamera);
            pEvento->stage();
            pFisico->update(dt);
            for(unsigned int i = 0; i < LE.getSize(); i++){
                pFisico->executarFisica(LE.operator[](i));
            }   
            updateVida();
            draw();
            LE.updateAll();
        }
    }
    void Fase::draw(){
        LE.drawAll();
        atualizaPontuacao();
    }
    void Fase::salvarJogo(){
    }
}

