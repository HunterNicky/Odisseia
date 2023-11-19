#include "Fases/Fase2.hpp"

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

namespace Fases{
    Fase2::Fase2(): 
        Fase(){
        loadMap();
    }

    Fase2::Fase2(nlohmann::json arquivoPersonagens):
        Fase(){
        recuperarJogada(arquivoPersonagens);
    }

    Fase2::~Fase2(){

    }

    void Fase2::newLava(sf::Vector2f pos, sf::Vector2f size){
        Entidades::Obstaculos::Lava* pLava = new Entidades::Obstaculos::Lava(pos, size, Entidades::ID::Lava);
        pLava->setGerenciadorDeColisao(pColisao);
        LE.push_back(static_cast<Entidades::Entidade*>(pLava));
    }

    void Fase2::recuperarJogada(nlohmann::json arquivoPersonagens){ 
        for (int i = 0; i < (int)arquivoPersonagens.size(); i++) {
            if (arquivoPersonagens[i]["ID"][0] == Entidades::ID::jogador){
                pJogador = new Entidades::Personagens::Jogador(arquivoPersonagens, i, Entidades::ID::jogador);
                pJogador->setGerenciadorDeColisao(pColisao);
                controleJog->setJogador(pJogador);
                LE.push_back(static_cast<Entidades::Entidade*>(pJogador));
            }
            else if (arquivoPersonagens[i]["ID"][0] == Entidades::ID::InimigoFacil){
                if(this->pJogador == nullptr){
                    std::cout << "ERRO EM RECUPERAR JOGADA!" << std::endl;
                    exit(1);
                }
                Entidades::Personagens::InimigoFacil* pInimigo = new Entidades::Personagens::InimigoFacil(arquivoPersonagens, i, Entidades::ID::InimigoFacil, pJogador);
                pInimigo->setGerenciadorDeColisao(pColisao);
                LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
            }
            else if (arquivoPersonagens[i]["ID"][0] == Entidades::ID::InimigoMedio) {
                if(pJogador == nullptr){
                    std::cout << "ERRO EM RECUPERAR JOGADA! 2" << std::endl;
                    exit(1);
                }
                Entidades::Personagens::InimigoMedio* pInimigo = new Entidades::Personagens::InimigoMedio(arquivoPersonagens, i, Entidades::ID::InimigoFacil, this->pJogador);
                pInimigo->setGerenciadorDeColisao(pColisao);
                LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
            }
            else if (arquivoPersonagens[i]["ID"][0] == Entidades::ID::InimigoDificil){
                if(pJogador == nullptr){
                    std::cout << "ERRO EM RECUPERAR JOGADA! 3" << std::endl;
                    exit(1);
                }
                Entidades::Personagens::InimigoDificil* pInimigo = new Entidades::Personagens::InimigoDificil(arquivoPersonagens, i, Entidades::ID::InimigoFacil, this->pJogador);
                pInimigo->setGerenciadorDeColisao(pColisao);
                LE.push_back(static_cast<Entidades::Entidade*>(pInimigo));
            }
            else if (arquivoPersonagens[i]["ID"][0] == Entidades::ID::Plataforma){
                Entidades::Obstaculos::ObstaculoFacil* pPlataforma = new Entidades::Obstaculos::ObstaculoFacil(arquivoPersonagens, i, Entidades::ID::Plataforma);
                pPlataforma->setGerenciadorDeColisao(pColisao);
                LE.push_back(static_cast<Entidades::Entidade*>(pPlataforma));
            } 
        }
    }

    void Fase2::loadMap(){
        
        std::ifstream file("data//mapa.txt");
        sf::Vector2f pos(0.f, 0.f);
        char numero;

        while(file.get(numero)){
            switch (numero)
            {
            case '0':
                pos.x += 20.f;
                break;
            case '1':
                pos.x += 20.f;
                newJogador(pos,sf::Vector2f(30.f, 50.f));
                break;
            case '2':
                pos.x += 20.f;
                newInimigo(pos, sf::Vector2f(20.f, 30.f));
                break;
            case 'i':
                pos.x += 20.f;
                newInimigoMedio(pos, sf::Vector2f(20.f, 30.f));
                break;
            case '3':
                pos.x += 200.f;
                newObstaculo(pos, sf::Vector2f(200.f, 50.f));
                break;
            case 'l':
                pos.x += 40.f;
                newLava(pos, sf::Vector2f(50.f, 10.f));
                break;
            default:
                pos.x = 0;
                pos.y += 50.f;
                break;
            }
        }
        file.close();
    }
    void Fase2::draw(){
        Fase::draw();
    }

    void Fase2::update(){
        executar();
    }

    void Fase2::executar(){
        Fase::executar();
    }
}
