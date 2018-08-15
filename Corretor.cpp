#include "Corretor.h"
#include "Palavra.h"
#include "Texto.h"
#include "Dicionario.h"

Corretor::Corretor( string nome_texto ) {
	texto.carregarNovoTexto(nome_texto);
}

void Corretor::iniciarCorrecao() {
	Palavra Null;
	Palavra atual = texto.percorrerTexto().minuscula();



	while(!(atual == Null)) {
		if(!dic.buscaPalavra(atual)) {
			apresentarErro(atual);
		}

		atual = texto.percorrerTexto().minuscula();
	}

	if(!wrongWords.empty()) {
		exibirErros();
		texto.salvarArquivo();
		dic.atualizarArquivo();
		return;
	}
	cout << "Não há erros no texto. Parabéns!!" << endl;
}

void Corretor::apresentarErro(Palavra palavraErrada){

	Palavra Null;
	Palavra pa = texto.getPalavraAnterior();
	Palavra pp = texto.getPalavraProximo();
	int op;
	std::cout << "=============================================" << "\n\n";
	cout << "Palavra errada encontrada: ";
	wcout << palavraErrada;
	cout << "\nContexto:\"...";
	wcout << pa << " " << palavraErrada << " " << pp << L"...\"\n ";
	cout << "\nPor favor selecione uma opção\n";
	cout << " -Opção 1: Inserir a palavra correta\n";
	cout << " -Opção 2: Ignorar o erro\n";
	cout << " -Opção 3: Selecionar palavra semelhante encontrada no dicionário\n";
	cout << " -Opção 4: Adicionar a palavra ao dicionário\n";

	adicionarErro(palavraErrada);

	do{
		cout << "Escolha a opcão desejada: " << endl;
		cout << ">>";
		cin >> op;
		if(op == 1){
			corrigir();
			break;
		}
		else if(op == 2){
			return;
			break;
		}
		else if(op == 3){
			Palavra correta = selecPalavraSemelhante(palavraErrada);
			if(!(correta == Null))
				texto.corrigirPalavra(correta);
			break;
		}
		else if(op == 4){
			adicionarPalavraDicionario(palavraErrada);
			break;
		}
		else{
			cout << "Opção inválida" << endl;
		}
	}while(op < 1 || op > 4);
}

void Corretor::corrigir(){// usar uma palavra fornecida pelo usuário para corrigir uma palavra errada no texto
	//permitir que o usuário insira uma palavra e substitua a palavra errada
	wstring correta;
	cout << "Insira a palavra correta: ";
	wcin.clear();
	wcin >> correta;

	texto.corrigirPalavra(correta);
}

Palavra Corretor::selecPalavraSemelhante(Palavra palavraErrada){//utilizar palavra semelhante sugerida
	//substituir palavra errada por palavra semelhante do dicionário
	queue<Palavra> iSemelhantes;

	iSemelhantes = dic.buscaSemelhante(palavraErrada, iSemelhantes);

	if(iSemelhantes.empty()) {
		Palavra Null;
		cout << "Palavra semelhante não encontrada no dicionario...\n" << endl;
		return Null;
	}

	int size = iSemelhantes.size();

	queue<Palavra> temp;

	cout << "Selecione qual palavra semelhante gostaria de escolher" << endl;

	int j;

	for( j = 0 ; j < size ; j++){
		wcout << L"[" << j+1 << L"]" << L" - " << iSemelhantes.front() << L" ";
		iSemelhantes.push(iSemelhantes.front());
		iSemelhantes.pop();
	}
	std::cout << "\n>>";

	Palavra escolhida;

	int op=0;

	do{
		cin >> op;
		if(op < j+1 && op > 0) {
			while(op-- > 0) {
				escolhida = iSemelhantes.front();
				iSemelhantes.pop();
			}
			return escolhida;
		} else {
			cout << "Selecione Opção válida" << endl;
			std::cout << ">>";
		}
	}while(!(op < j+1 && op > 0));

	while(!iSemelhantes.empty())
		iSemelhantes.pop();
}

void Corretor::adicionarPalavraDicionario(Palavra palavraErrada){
	dic.incluir(palavraErrada);
}

void Corretor::adicionarErro(Palavra palavraErrada){
	//se palavra não encontrada no dicionário, adicionar erro na lista
	//caso mesmo erro ocorra novamente, aumentar contagem
	//apresentarErro
	wstring P = palavraErrada.getPalavra();
	erros * r = new erros;
	r -> contador = 0;

	if(wrongWords.empty()){
		r ->palavra = P;
		r ->contador = r ->contador + 1;
		wrongWords.push_front(*r);
	}
	else{
		std::forward_list<erros>::iterator it;
		for(it=wrongWords.begin(); it != wrongWords.end(); it++){
			if(it ->palavra == P){
				it ->contador = it ->contador + 1;
				return;
			}
		}
		r ->palavra = P;
		r ->contador = r ->contador + 1;
		wrongWords.push_front(*r);
	}
}

void Corretor::exibirErros() {
	std::cout << "=============================================" << "\n\n";
	std::cout << "Sem mais erros!" << "\n\n";
	std::cin.ignore();
	std::cout << "=============================================" << "\n";
	std::cout << "Lista de Erros:" << "\n";
	std::forward_list<erros>::iterator it;
	wrongWords.reverse();
	for(it = wrongWords.begin() ; it != wrongWords.end() ; it++){
		wcout << it -> palavra << ": " << L"Errou " << it -> contador << L" vez(es)" << endl;
	}
	std::cin.ignore();
	while(!wrongWords.empty())
		wrongWords.pop_front();
}
