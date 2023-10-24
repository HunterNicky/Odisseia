namespace Entidades{
    namespace Obstaculos{
        class Obstaculo{
        private:
            //...
        public:
            Obstaculo();
            ~Obstaculo();
            virtual void executar() = 0;
            //...
        };
    }
}
