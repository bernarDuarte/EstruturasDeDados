#include <iostream>
using namespace std;

#include "lista.h"
#include "jogador.h"


int main()
{
    TListaEstatica<Jogador,7> jogadores;
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
    
    //testes das funções da lista
    inicializa(jogadores);
    insere_inicio(jogadores, c);
    insere_inicio(jogadores,d);
    insere_inicio(jogadores,a);
    insere_final(jogadores, b);
    insere_posicao(jogadores, a,2);
    insere_posicao(jogadores, d, 1);
    // FAZER COM O OBTER remove_inicio(jogadores,4);
    //insere_inicio(jogadores,obter_item_lista(jogadores, 5));
    
    cout << jogadores;
    cout << jogadores.quantidade;
}