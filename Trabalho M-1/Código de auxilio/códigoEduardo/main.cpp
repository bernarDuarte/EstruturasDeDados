#include <iostream>

#include "lista.h"
#include "carta.h"

int main() {

    TListaEstatica<TCarta,52> mesa;
    inicializar_lista(mesa);

    TListaEstatica<TJogador,4> jogadores;
    inicializar_lista(jogadores);

    TJogador jogador1;
    jogador1.nome = "Eduardo";
    inicializar_lista(jogador1.mao);
    inserir_inicio_lista(jogadores,jogador1);

    preencher_lista_cartas(mesa);

    distribuir_carta_damesa_parajogador(mesa,jogadores,0);
    distribuir_carta_damesa_parajogador(mesa,jogadores,0);
    distribuir_carta_damesa_parajogador(mesa,jogadores,0);

//    distribuir_carta_damesa_parajogador(mesa,jogadores);

    cout << "Imprimindo mesa" << endl;
    cout << mesa;
    cout << "Imprimindo jogador" << endl;
    cout << jogadores;


    return 0;
}
