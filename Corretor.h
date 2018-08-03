#ifndef CORRETOR_H
#define CORRETOR_H

#include "Palavra.h"
#include "Texto.h"
#include "dicionario.h"
  
#include <string>
#include <forward_list>

class Corretor {
private:
	Texto tex;
	Dicionario dic;
	Palavra pal;	
	struct erros{
		string palavra;
		int contador;
	};

public:
	void adicionarErro();
	void apresentarErro();
	void corrigir();// usar uma palavra fornecida pelo dicionário para corrigir uma palavra errada no texto
	void ignorar();//ignorar um erro encontrado pelo corretor e não fazer mais nada
	void adicionarDicionario();
};
