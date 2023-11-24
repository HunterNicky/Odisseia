#include "Menu/MenuGameOver.hpp"
#include "Estados/Estado.hpp"
#include "Fases/Fase.hpp"
#include "Menu/Menu.hpp"
#include <memory>
#include <string>

namespace Menu {
    MenuGameOver::MenuGameOver(Fases::Fase *pFase): 
        Menu(3, 2, sf::Vector2f(POS_TEXTO_GO_X - TAMANHO_GO_X*2, POS_TEXTO_GO_Y - TAMANHO_GO_Y /2), sf::Vector2f(TAMANHO_GO_X, TAMANHO_GO_Y), "GAME OVER", 100), 
        pFase(pFase),
        fundoCaracter(new sf::RectangleShape()),
        texto(sf::Vector2f(POS_TEXTO_X, POS_TEXTO_Y), sf::Vector2f(TAMANHO_GO_X, TAMANHO_GO_Y), "", 30),
        pontuacao(sf::Vector2f(POS_PONTUACAO_X, POS_PONTUACAO_Y), sf::Vector2f(TAMANHO_GO_X, TAMANHO_GO_Y), "Pontuacao",  35){
        inicializaBotao();
        titulo.setColor(sf::Color::Red);
        titulo.setTextFont(CAMINHO_FONTE_MENU);
        pontuacao.setColor(sf::Color::White);
        pontuacao.setTextFont(CAMINHO_FONTE_MENU);
        texto.setColor(sf::Color::Blue);
        texto.setTextFont(CAMINHO_FONTE_MENU);

        if(pFase == nullptr){
            std::cout << " Erro no Ponteiro da Fase! " << std::endl;
            exit(1);
        }
        std::string pontos = std::to_string(pFase->getPontuacaoJog());

        while(pontos.size() < 5){
            std::string aux = pontos;
            pontos = '0' + aux;
        }   
        pontuacao.setTexto("Pontuacao: " + pontos);
        sf::Texture* textura = new sf::Texture();
        if(!textura->loadFromFile("data/Botao/CaixaTexto.png")){
            std::cout << "Jungle::Menu::MenuGameOver::nao foi possivel carregar textura" << std::endl;
            exit(1);
        }
        fundoCaracter->setTexture(textura);
        fundoCaracter->setSize(sf::Vector2f(400.f, 70.f));
        fundoCaracter->setPosition(sf::Vector2f(650.f - fundoCaracter->getSize().x / 2.0f, 200.f));
        sf::Vector2f posCaixa = fundoCaracter->getPosition();
        sf::Vector2f tamCaixa = fundoCaracter->getSize();
        sf::Vector2f tamCaixaPontuacao = fundoCaracter->getSize();
        texto.setPos(sf::Vector2f(posCaixa.x + tamCaixa.x / 2.0f - texto.getSize().x / 2.0f + 40.f, posCaixa.y + tamCaixa.y / 2.0f - texto.getSize().y / 2.0f +5.f));
        pontuacao.setPos(sf::Vector2f(posCaixa.x + tamCaixaPontuacao.x / 2.0f - pontuacao.getSize().x / 2.0f -80.f, posCaixa.y + tamCaixaPontuacao.y / 2.0f - pontuacao.getSize().y / 2.0f + 80.0f));
    }

    MenuGameOver::~MenuGameOver(){}

    void MenuGameOver::setFase(Fases::Fase* pFase){
        this->pFase = pFase;
    }
    void MenuGameOver::inicializaBotao(){
        Botoes::Botao* pBotao = NULL;
         
        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f ), std::string(" Salvar Colocacao"));
        pBotao->selecionado(true);

        Menu::lBotao.push_back(pBotao);
        Menu::it = Menu::lBotao.begin();

        pBotao = new Botoes::Botao(sf::Vector2f(640.f - 100, 360.f + 100), std::string(" Menu"));
        Menu::lBotao.push_back(pBotao);
        numOpc = 2;
    }

    //Ideia de código monitor Giovane
    void MenuGameOver::salvarPontuacao(){
        std::string nome = texto.getText();
        if(nome == ""){
            nome = "SemNome";
        }
        std::string pontos = pontuacao.getText().substr(11, pontuacao.getText().length());
        std::string linha = nome + " " + pontos + " ";

        std::ofstream arquivo("data/Colocacao/colocacao.txt");
        if(!arquivo){
            std::cout << "Erro ao abrir arquivo Colocao!" << std::endl;
            exit(1);
        }
        arquivo << linha << std::endl;
        arquivo.close();
    }
    void MenuGameOver::ajustarTexto(){
        sf::Vector2f posCaixa = fundoCaracter->getPosition();
        sf::Vector2f tamCaixa = fundoCaracter->getSize();
        texto.setPos(sf::Vector2f(posCaixa.x + tamCaixa.x/2 - 80.f , posCaixa.y + tamCaixa.y/2 - 30.f) );
    }
    void MenuGameOver::addCaracter(char caracter){
        std::string nome = texto.getText();
        if(nome.length() <= 10){
            nome += caracter;
            texto.setTexto(nome);
            ajustarTexto();
        }
    }
    void MenuGameOver::removerCaracter(){
        std::string nome = texto.getText();
        if(nome != ""){
            nome = nome.substr(0, nome.length() - 1);
            texto.setTexto(nome);
            ajustarTexto();
        }
    }
    void MenuGameOver::executar(){
        switch (numSelec) {
            case 0:
                salvarPontuacao();
                break;
            case 1:
                pMaquinaDeEstado->popEstado();
                pMaquinaDeEstado->popEstado();
                if(pMaquinaDeEstado->getEstadoAtual()->getID() == 1){//Menu de opções
                    pMaquinaDeEstado->popEstado();
                }
                break;
            default:
                break;
        }
    }

    void MenuGameOver::update(const double dt){
        Menu::update(dt);
    }
    void MenuGameOver::draw(){
        //pFase->draw();

        Menu::draw();
        pGrafico->draw(dynamic_cast<sf::Drawable*>(fundoCaracter));
        pGrafico->draw(texto.getSfTexto());
        pGrafico->drawText(pontuacao.getSfTexto());
        
    }
}