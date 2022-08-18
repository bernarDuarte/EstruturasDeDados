#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
using namespace std;


#include "lista.h"



struct Jogador {
	int num;
	int pontuacao;
};

//imprime
ostream& operator<<(ostream& os,Jogador j) {
	os << "Jogador: " << j.num << " Pontuação: " << j.pontuacao<<endl;
	return os;
}




#endif
