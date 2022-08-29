#ifndef JOGADOR_H
#define JOGADOR_H
#include "lista.h"
#include <iostream>
using namespace std;
#include "lista.h"

struct Jogador {
	int num;
	int pontuacao;
};

void cria_jogador(TListaEstatica<Jogador,100> &lista) {	
	for (int i = 0; i < 100;i++) {
		Jogador c;
		c.num = i;
		c.pontuacao = 0;
		insere_inicio(lista,c);
	}
}

//imprime
ostream& operator<<(ostream& os,Jogador j) {
	os << "Jogador: " << j.num << " Pontuação: " << j.pontuacao<<endl;
	return os;
}

#endif
