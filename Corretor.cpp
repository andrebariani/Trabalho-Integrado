#include "Corretor.h"
#include "Palavra.h"
#include "Texto.h"
#include "dicionario.h"
#include <iostream>
#include <string>
#include <forward_list>

Corretor::Corretor( string nome_texto ) {
	texto.carregarNovoTexto(nome_texto);
}

// void mudarTexto( string nome_texto ) {
// 	texto.carregarNovoTexto(nome_texto);
// }

void Corretor::iniciarCorrecao() {
	Palavra Null;
	Palavra atual = texto.percorrerTexto();

	while(!(atual == Null)) {
		Palavra encontrado = dicionario.buscaPalavra(atual);
		if(encontrado == Null) {
			apresentarErro(atual);
		}

		texto.percorrerTexto();
	}

	if(!palavrasErradas.empty()) {
		exibirErros();
		texto.salvarArquivo();
		return;
	}
	cout << "Não há erros no texto. Parabéns!!" << endl;
}

void Corretor::apresentarErro(Palavra palavraErrada){

	Palavra pa = texto.getPalavraAnterior();
	Palavra pp = texto.getPalavraProximo();
	int op;

	cout << "Uma palavra inexistente no dicionário foi encontrada no texto: \"...";
	wcout << pa << palavraErrada << pp << L"...\", por favor selecione uma opção\n";
	cout << "Opção 1: Inserir a palavra correta\n"
	cout << "Opção 2: Ignorar o erro\n"
	cout << "Opção 3: Selecionar palavra semelhante encontrada no dicionário\n"
	cout << "Opção 4: Adicionar a palavra ao dicionário\n"

	adicionarErro(palavraErrada);

		cin >> op;
	do{
		if(op == 1){
				corrigir(palavraErrada);
			break;
		}
		else if(op == 2){
				return;
			break;
		}
		else if(op == 3){
			Palavra correta = selecPalavraSemelhante(palavraErrada);
			texto.corrigirPalavra(correta);
			break;
		}
		else if(op == 4){
			adicionarPalavraDicionario(palavraErrada);
			break;
		}
		else{
			cout << "Opção inválida";
			cin >> op;
		}
	}while(op < 1 || op > 4);


}

void mudarTexto( string nome_texto ) {
	texto.carregarNovoTexto(nome_texto);
}

void Corretor::corrigir(){// usar uma palavra fornecida pelo usuário para corrigir uma palavra errada no texto
	//permitir que o usuário insira uma palavra e substitua a palavra errada
	wstring correta;
	cout << "Insira a palavra correta";
	wcin >> correta;

	texto.corrigirPalavra(correta);

		//corrigirPalavra - texto.cpp
}

Palavra Corretor::selecPalavraSemelhante(Palavra palavraErrada){//utilizar palavra semelhante sugerida
	//substituir palavra errada por palavra semelhante do dicionário
	queue<Palavra> *iSemelhantes = dic.buscaSemelhante(palavraErrada);
	int j;

	int size = iSemelhantes->size();

	queue<Palavra> temp;

	cout << "Selecione qual palavra semelhante gostaria de escolher" << endl;
	for( j = 0; j < (iSemelhantes -> size() - 1); j++){
		temp.push(iSemelhantes -> front());
		wcout << j << L" - " << temp.front() << endl;
		iSemelhantes -> pop();
	}

	Palavra escolhida;

	int op;
	cin >> op;
	while(1){
		switch(op < j && op > 0) {
			case 1:
				while(op-- > 0) {
					escolhida = temp.pop();
				}
				return escolhida;
			break;
			default:
				cout << "Selecione Opção válida" << endl;
			break;
		}
	}
}

void Corretor::adicionarPalavraDicionario(Palavra palavraErrada){
	dic.incluir(palavraErrada);
}

void Corretor::adicionarErro(Palavra palavraErrada){
	//se palavra não encontrada no dicionário, adicionar erro na lista
	//caso mesmo erro ocorra novamente, aumentar contagem
	//apresentarErro
	wstring P = palavraErrada;

	if(wrongWords.empty()){
		erros r;
		r.palavra = P;
		r.contador = r.contador + 1;
		wrongWords.assign(r);
	}
	else{
		std::forward_list<erros>::iterator it;
		for(it=wrongWords.begin(); it != wrongWords.end(); it++){
			if(r.palavra == P){
				r.contador = r.contador + 1;
			}
			else if((r.palavra != P) && ((i+1)==wrongWords.end())) {
			erros r;
			r.palavra = P;
			r.contador = r.contador + 1;
			wrongWords.push_front(r);
			}
		}
	}
}

void Corretor::exibirErro() {
	std::forward_list<erros>::iterator it;
	for(it=wrongWords.begin(); it != wrongWords.end(); it++){
		wcout << (*it) << L"Errou " << (*it).contador << L"Vezes" << endl;
	}
}


//
//
//
// // OLD VERSION
// //lista das palavras erradas
// 	forward_list<erros> wrongWords;
//
// //main(){
// 	//utilizar funções:
// 	//		percorrerTexto - Texto.cpp
// 	//		consulta - dicionario.cpp
// 	// try catch
// //}
//
// 	void Corretor::adicionarErro(Palavra palavraErrada){
// 		//se palavra não encontrada no dicionário, adicionar erro na lista
// 		//caso mesmo erro ocorra novamente, aumentar contagem
// 		//apresentarErro
//
//
// 		if(wrongWords.empty()){
// 			erros r;
// 			r.palavra = P;
// 			r.contador = r.contador + 1;
// 			wrongWords.assign(r);
// 		}
// 		else{
// 			for(int i=wrongWords.begin(); i != wrongWords.end(); i++){
// 				if(r.palavra == P){
// 					r.contador = r.contador + 1;
// 				}
// 				else if((r.palavra != P) && ((i+1)==wrongWords.end())) {
// 				erros r;
// 				r.palavra = P;
// 				r.contador = r.contador + 1;
// 				wrongWords.push_front(r)
// 				}
// 			}
// 		}
// 	}
//
//
//
//
// 	void Corretor::apresentarErro(Palavra palavraErrada){
// 		//apresentar contexto
// 		//oferecer opções
// 		//utilizar função: contexto - texto.cpp
// 		contexto();
// 		int op;
//
// 		cout << "Uma palavra inexistente no dicionário foi encontrada no texto: \"..." <<tex.getPalavraAnterior << palavraErrada << tex.getPalavraProximo <<"...\", por favor selecione uma opção\n";
// 		cout << "Opção 1: Inserir a palavra correta\n"
// 		cout << "Opção 2: Ignorar o erro\n"
// 		cout << "Opção 3: Selecionar palavra semelhante encontrada no dicionário\n"
// 		cout << "Opção 4: Adicionar a palavra ao dicionário\n"
//
// 			cin >> op;
// 		do{
// 			if(op == 1){
// 				corrigir();
// 				break;
// 			}
// 			else if(op == 2){
// 				ignorarErro();
// 				break;
// 			}
// 			else if(op == 3){
// 				selecPalavraSemelhante();
// 				break;
// 			}
// 			else if(op == 4){
// 				adicionarDicionario();
// 				break;
// 			}
// 			else{
// 				cout << "Opção inválida";
// 				cin >> op;
// 			}
// 		}while(op < 1 || op > 4);
//
//
// 	}
//
// 	//opções do corretor
// 	void Corretor::corrigir(){// usar uma palavra fornecida pelo usuário para corrigir uma palavra errada no texto
// 		//permitir que o usuário insira uma palavra e substitua a palavra errada
// 		string correta;
// 		cout << "Insira a palavra correta";
// 		cin >> correta;
//
// 		tex.corrigirPalavra(correta);
//
// 			//corrigirPalavra - texto.cpp
// 	}
//
// 	int Corretor::ignorarErro(){//ignorar um erro encontrado pelo corretor e não fazer mais nada
// 		return 0;
// 	}
//
// 	Palavra Corretor::selecPalavraSemelhante(Palavra p){//utilizar palavra semelhante sugerida
// 		//substituir palavra errada por palavra semelhante do dicionário
// 		Palavra *iSemelhantes;
// 		int j;
//
// 		iSemelhantes = dic.PalavraSemelhante(p);
// 		for(j = 1; j < 6; j++){
// 			cout << j << "-" << *iSemelhantes << endl;
// 			iSemelhantes++;
// 		}
// 	}
//
// 	void Corretor::adicionarDicionario(Palavra palavraErrada){
// 		//classe inclusão - Dicionario.cpp
// 	}
