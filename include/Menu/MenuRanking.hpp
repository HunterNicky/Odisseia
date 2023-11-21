#include "Menu.hpp"

#define TAM_TEXTO_RANKING_X 100.f
#define TAM_TEXTO_RANKING_Y 100.f
#define POS_TEXTO_RANKING_X 640.f
#define POS_TEXTO_RANKING_Y 100.f

namespace Menu {
    class MenuRanking: public Menu{
    private:
        
    public:
        MenuRanking();
        ~MenuRanking();
        void inicializaBotao();
        void executar();
        void update(const double dt);
        void draw();
    };
}