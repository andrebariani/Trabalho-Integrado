#ifndef CORRETOR_H
#define CORRETOR_H
  
#include<string>

class Corretor {
private:
	Palavra semelhantes[10000];
	Palavra erros[10000];
	Texto tex;
	Dicionario dic;

public:
	void corrigirPalavra();
	void ignorarErro();
	Palavra selecPalavraSemelhante(Palavra p);
	void addPalavraDic(Palavra p);
};