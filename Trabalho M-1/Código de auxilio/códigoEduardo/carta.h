#ifndef CARTA_H
#define CARTA_H

#include <iostream>
using namespace std;

#include "lista.h"

// 1. Tipo de dado aderente ao problema do jogo de cartas
struct TCarta {
    int naipe;
    int valor;
};

std::ostream& operator<<(std::ostream& saida, TCarta c) {
    saida << "TCarta { naipe: " << c.naipe << ", valor: "<< c.valor << "}";
    return saida;
}

struct TJogador {
    TListaEstatica<TCarta,3> mao;
    string nome;
};

std::ostream& operator<<(std::ostream& saida, TJogador player) {
    saida << "TJogador { nome: " << player.nome << ", Cartas: "<< player.mao << "}";
    return saida;
}


void distribuir_carta_damesa_parajogador(TListaEstatica<TCarta,52> &mesa,
                                         TListaEstatica<TJogador, 4> &jogador,
                                         int posicao_jogador) {

    TJogador jogador_atual = obter_posicao_lista(jogador,posicao_jogador);
    try {
        inserir_inicio_lista(jogador_atual.mao, obter_posicao_lista(mesa,0) );
        remover_inicio_lista(mesa);
    } catch(const char* msg) {
        cerr << "Deu ruim: " << msg << endl;
    }

}

template <typename T,int CAPACIDADE>
void preencher_lista_cartas(TListaEstatica<T, CAPACIDADE> & lista) {

    for(int naipe = 0; naipe < 4; naipe++) {
        for(int valor = 0; valor < 13; valor++) {
            TCarta c;
            c.naipe = naipe;
            c.valor = valor;
            inserir_inicio_lista(lista,c);
        }
    }
}

#endif // CARTA_H
