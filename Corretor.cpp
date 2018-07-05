#include "Corretor.h"
#include "Palavra.h"
#include "Texto.h"
#include "Arvore.h"
#include "dicionario.h"
#include <iostream>
#include <string>

lista das palavras erradas
	utilizar funções:
			percorrerTexto - Texto.cpp
			consulta - dicionario.cpp


	void apresentarErro(){
		erro encontrado
		adicionarErro
		apresentar contexto
		oferecer opções
	}

	void adicionarErro(){
		se palavra não encontrada no dicionário, adicionar erro na lista
		caso mesmo erro ocorra novamente, aumentar contagem
	}

	//opções do corretor 
	void corrigirPalavra(){// usar uma palavra fornecida pelo dicionário para corrigir uma palavra errada no texto
		permitir que o usuário insira uma palavra no dicionário e substitua a palavra errada

		utilizar funções:
			inclusao - dicionario.cpp
			corrigirPalavra - texto.cpp

	}
	
	void ignorarErro(){//ignorar um erro encontrado pelo corretor e não fazer mais nada
		adicionarErro
		return 0 
	}

	Palavra selecPalavraSemelhante(Palavra p){//utilizar palavra semelhante sugerida
		substituir palavra errada por palavra semelhante do dicionário

		utilizar funções:
			semelhantes - palavra.cpp
	}