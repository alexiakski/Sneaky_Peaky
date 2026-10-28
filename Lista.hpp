#ifndef LISTA_HPP
#define LISTA_HPP

template <typename TL>
class Lista
{
    public:

        Lista();
        ~Lista();

        void incluir (*TL);
        void limpar();
        void imprimir();
        void percorrer();


    class Elemento
    {
        private:

            TL *pInfo;
            Elemento *pProx;

        public:

            Elemento(TL *pInfo);
            ~Elemento();

            TL* getInfo();
            void setProx(Elemento *pProx);
            void incluir (TL *pInfo);
            Elemento* const getProx();

    };

    private:

        Elemento *pInicio;
        Elemento *pFim;
};

#endif