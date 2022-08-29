#ifndef LISTA_ENCADEADA_SIMPLES_H_INCLUDED
#define LISTA_ENCADEADA_SIMPLES_H_INCLUDED

template <typename TIPO>
struct Telemento {
    TIPO dado;
    Telemento <TIPO>* proximo;
};

template <typename TIPO>
struct Tlista {
    Telemento <TIPO>* inicio;
};


//Inicia
template <typename TIPO>
void inicializar(Tlista <TIPO>& p) {

    p.inicio = NULL;
}


//Cria elemento
template <typename TIPO>
Telemento <TIPO>* novo_elemento_lista(TIPO dado) {

    Telemento <TIPO>* novo = new Telemento<TIPO>;

    novo->dado = dado;
    novo->proximo = NULL;

    return novo;
}


//inserir
template <typename TIPO>
bool insereInicio(Tlista <TIPO>& lista, TIPO dado) {


    Telemento <TIPO>* novo = novo_elemento_lista(dado);

    if (lista.inicio == NULL) {
        lista.inicio = novo;
        return true;
    }
    else {

        novo->proximo = lista.inicio;
        lista.inicio = novo;
        return true;
    }
}


template <typename TIPO>
bool inserePosicao(Tlista <TIPO>& lista, TIPO dado, int p) {

    int qtt = contaLista(lista), i = 0;

    Telemento<TIPO>* novo = novo_elemento_lista(dado);
    Telemento<TIPO>* nav = lista.inicio;
    Telemento<TIPO>* anterior;

    if (lista.inicio == NULL || p > qtt || p < 0) {
        return false;
    }
    if (p == qtt) {
        insereFinal(lista, dado);
        return true;
    }if (p == 0) {
        insereInicio(lista, dado);
        return true;
    }
    else {

        while (i < p) {
            anterior = nav;
            nav = nav->proximo;
            i++;
        }
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
        return true;
    }
}


template <typename TIPO>
bool insereFinal(Tlista <TIPO>& lista, TIPO dado) {

    Telemento<TIPO>* nav = lista.inicio;

    if (lista.inicio != NULL) {

        while (nav->proximo != NULL)
            nav = nav->proximo;


        if (nav->proximo != NULL) {
            return false;

        }
        else {
            Telemento <TIPO>* novo = novo_elemento_lista(dado);
            novo->proximo = nav->proximo;
            nav->proximo = novo;
            //     cout << "teste: "<< dado.nome<< endl;
            //     cout << "endereco: "<< nav << endl;
            //    cout << "proximo end: "<< novo << endl;
            return true;
        }

    }
    else {
        Telemento <TIPO>* novo = novo_elemento_lista(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        // cout << "teste: "<< dado.nome<< endl;
        // cout << "endereco: "<< nav << endl;
        // cout << "proximo end: "<< novo << endl;
        return true;
    }


}



//Remover
template <typename TIPO>
bool removeInicio(Tlista <TIPO>& lista) {

    if (lista.inicio == NULL) {
        return false;
    }
    else {
        Telemento<TIPO>* removedor = lista.inicio;
        lista.inicio = removedor->proximo;
        delete removedor;
        return true;
    }
}


template <typename TIPO>
bool removePosicao(Tlista <TIPO>& lista, int p) {

    int qtt = contaLista(lista), i = 0;

    Telemento<TIPO>* nav = lista.inicio;
    Telemento<TIPO>* depois;

    if (lista.inicio == NULL || p > qtt || p < 0) {
        return false;
    }
    if (p == qtt - 1) {
        removeFinal(lista);
        return true;
    }if (p == 0) {
        removeInicio(lista);
        return true;
    }
    else {

        while (i < p) {
            depois = nav;
            nav = nav->proximo;
            i++;
        }
        depois->proximo = nav->proximo;
        delete depois;
        return true;
    }
}


template <typename TIPO>
bool removeFinal(Tlista <TIPO>& lista) {

    Telemento<TIPO>* nav = lista.inicio;
    Telemento<TIPO>* ultimo;
    if (lista.inicio == NULL) {
        return false;
    }
    else {
        while (nav->proximo != NULL) {
            ultimo = nav;
            nav = nav->proximo;
        }
        ultimo->proximo = NULL;
        delete ultimo;
        return true;
    }
}


//quantidade
template <typename TIPO>
int contaLista(Tlista <TIPO>& lista) {

    int qtt = 0;

    Telemento<TIPO>* nav = lista.inicio;

    if (lista.inicio == NULL) {
        cout << "Lista Vazia!" << endl;
    }
    else {

        while (nav != NULL) {
            nav = nav->proximo;
            qtt++;
        }
        return qtt;
    }


}


template<typename T>
void imprime_simples(Tlista<T> lista) {
    Telemento<T> *nav = new Telemento<T>;
    nav = lista.inicio;
    while (nav != NULL) {
        cout << "\n--------------------------------------";
        cout << "\nJOGADOR: " << nav->dado.num;
        cout << "\nPONTUACAO: " << nav->dado.pontuacao;
        cout << "\n--------------------------------------";
        nav = nav->proximo;
    }
}

#endif // LISTA_ENCADEADA_SIMPLES



