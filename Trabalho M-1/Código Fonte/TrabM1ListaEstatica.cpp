#include <iostream>
using namespace std;

#include "lista.h"
#include "jogador.h"
#include "lista_dinam_dupl.h"

int main()
{
    TListaEstatica<Jogador,100> jogadores;
    //Tlista<Jogador> players;
    TLista<Jogador> duplaJogadores;
    
    inicializar(duplaJogadores);
    

    Jogador c;
    c.num = 1;
    c.pontuacao = 1;
    Jogador d;
    d.num = 2;
    d.pontuacao = 2;
    Jogador a;
    a.num = 3;
    a.pontuacao = 3;

    Jogador b;
    b.num = 4;
    b.pontuacao = 4;

    inserirInicio(duplaJogadores, c);
    imprimir_dupla(duplaJogadores);





    /*
    

    inicializar(players);
    insereInicio(players, c);
    insereInicio(players, d);
    insereInicio(players, b);
    insereInicio(players, a);
    insereInicio(players, a);
    insereInicio(players, a);
    imprime_simples(players);
    
    

    cria_jogador(jogadores);
    int contador = 0;
    while (contador < 100) {
        cout << jogadores.vetor[contador];
        contador++;
    }
    
    
    //testes das funções da lista
    inicializa(jogadores);
    insere_inicio(jogadores, c);
    insere_inicio(jogadores,d);
    insere_inicio(jogadores,a);
    insere_final(jogadores, b);
    insere_posicao(jogadores, a,2);
    insere_posicao(jogadores, d, 1);
    
    insere_inicio(jogadores,obter_item_lista(jogadores, 5));
    Jogador h = obter_item_lista(jogadores, 5);
    
    cout << jogadores;
    */
}