#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>

using namespace std;

// 3. Estrutura base da TAD de jogo de cartas
template <typename T,int CAPACIDADE>
struct TListaEstatica{
    T vetor[CAPACIDADE];
    int quantidade;
};


template <typename T,int CAPACIDADE>
ostream& operator<<(ostream& os, TListaEstatica<T, CAPACIDADE> lista) {
    if(lista.quantidade == 0) {
        os << "Lista vazia" << endl;
    } else {
        for(int i = 0; i < lista.quantidade; i++) {
            os << "Lista[" << i << "]: " << lista.vetor[i] << endl;
        }
    }
    return os;
}

template <typename T,int CAPACIDADE>
void inicializar_lista(TListaEstatica<T, CAPACIDADE> &lista) {
    lista.quantidade = 0;
}

template <typename T,int CAPACIDADE>
void inserir_inicio_lista(TListaEstatica<T, CAPACIDADE> &lista, T dado) {

    if( lista.quantidade >= CAPACIDADE ) {
        throw "Lista cheia!";
    }

    // Deslocar elementos
    for(int i = lista.quantidade; i > 0; i--) {
        lista.vetor[i] = lista.vetor[i-1];
    }

    lista.vetor[0] = dado;
    lista.quantidade++;

}


template <typename T,int CAPACIDADE>
void imprimir_lista(TListaEstatica<T, CAPACIDADE> lista) {

    if(lista.quantidade == 0) {
        cout << "Lista vazia" << endl;
    } else {
        for(int i = 0; i < lista.quantidade; i++) {
            cout << "Lista[" << i << "]: " << lista.vetor[i] << endl;
        }
    }
}

template <typename T,int CAPACIDADE>
void remover_inicio_lista(TListaEstatica<T, CAPACIDADE> &lista) {

    if(lista.quantidade == 0) {
        throw "LIST UNDERFLOW";
    }

    for(int i = 1; i < lista.quantidade; i++) {
        lista.vetor[i-1] = lista.vetor[i];
    }

    lista.quantidade--;

}

template <typename T,int CAPACIDADE>
T& obter_posicao_lista(TListaEstatica<T,CAPACIDADE> lista, int posicao) {

    if(posicao < 0 || posicao >= lista.quantidade) {
        throw "Invalid index";
    }

    return lista.vetor[posicao];
}



#endif
