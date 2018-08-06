#include "Corretor.h"
#include "Palavra.h"
#include "Texto.h"
#include "dicionario.h"
#include <iostream>
#include <string>
#include <forward_list>

//lista das palavras erradas
	forward_list<erros> wrongWords;

//main(){
	//utilizar funções:
	//		percorrerTexto - Texto.cpp
	//		consulta - dicionario.cpp
	// try catch
//}
	
	void Corretor::adicionarErro(Palavra palavraErrada){
		//se palavra não encontrada no dicionário, adicionar erro na lista
		//caso mesmo erro ocorra novamente, aumentar contagem
		//apresentarErro
		

		if(wrongWords.empty()){
			erros r;
			r.palavra = P;
			r.contador = r.contador + 1;
			wrongWords.assign(r);
		}
		else{
			for(int i=wrongWords.begin(); i != wrongWords.end(); i++){
				if(r.palavra == P){
					r.contador = r.contador + 1;
				}
				else if((r.palavra != P) && ((i+1)==wrongWords.end())) {
				erros r;
				r.palavra = P;
				r.contador = r.contador + 1;	
				wrongWords.push_front(r)
				}
			}
		}
	}

		
	

	void Corretor::apresentarErro(Palavra palavraErrada){
		//apresentar contexto
		//oferecer opções
		//utilizar função: contexto - texto.cpp
		contexto();
		int op;

		cout << "Uma palavra inexistente no dicionário foi encontrada no texto: \"..." <<tex.getPalavraAnterior << palavraErrada << tex.getPalavraProximo <<"...\", por favor selecione uma opção\n";
		cout << "Opção 1: Inserir a palavra correta\n"
		cout << "Opção 2: Ignorar o erro\n"
		cout << "Opção 3: Selecionar palavra semelhante encontrada no dicionário\n"
		cout << "Opção 4: Adicionar a palavra ao dicionário\n"

			cin >> op;
		do{
			if(op == 1){
				corrigir();
				break;
			}
			else if(op == 2){
				ignorarErro();
				break;
			}
			else if(op == 3){
				selecPalavraSemelhante();
				break;
			}
			else if(op == 4){
				adicionarDicionario();
				break;
			}
			else{
				cout << "Opção inválida";
				cin >> op;
			}
		}while(op < 1 || op > 4);


	}

	//opções do corretor 
	void Corretor::corrigir(){// usar uma palavra fornecida pelo usuário para corrigir uma palavra errada no texto
		//permitir que o usuário insira uma palavra e substitua a palavra errada
		string correta;
		cout << "Insira a palavra correta";
		cin >> correta; 

		tex.corrigirPalavra(correta);
			
			//corrigirPalavra - texto.cpp
	}
	
	int Corretor::ignorarErro(){//ignorar um erro encontrado pelo corretor e não fazer mais nada
		return 0; 
	}

	Palavra Corretor::selecPalavraSemelhante(Palavra p){//utilizar palavra semelhante sugerida
		//substituir palavra errada por palavra semelhante do dicionário
		Palavra *iSemelhantes;
		int j;

		iSemelhantes = dic.PalavraSemelhante(p);
		for(j = 1; j < 6; j++){
			cout << j << "-" << *iSemelhantes << endl;
			iSemelhantes++;
		}
	}

	void Corretor::adicionarDicionario(Palavra palavraErrada){
		//classe inclusão - Dicionario.cpp
	}

