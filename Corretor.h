#ifndef CORRETOR_H
#define CORRETOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include "Palavra.h"
#include "Texto.h"
#include "dicionario.h"

using namespace std;

class Corretor {
    private:
    	Texto texto;
    	dicionario dic;
        typedef struct {
            wstring palavra;
            int contador;
        } erros;
        forward_list<erros> wrongWords;
    	// Palavra pal;

    public:
        Corretor(std::string nometexto);
        void iniciarCorrecao(); // Inicia processo de correção do arquivo de texto inteiro
        void apresentarErro(Palavra palavraErrada);
        // void mudarTexto( string nome_texto );
        void corrigir();
        Palavra selecPalavraSemelhante(Palavra palavraErrada);
        void adicionarPalavraDicionario(Palavra palavraErrada);
    	void adicionarErro(Palavra palavraErrada);
        void exibirErros();
    	// void apresentarErro();
    	// void corrigir();// usar uma palavra fornecida pelo dicionário para corrigir uma palavra errada no texto
    	// void ignorar();//ignorar um erro encontrado pelo corretor e não fazer mais nada
};


#endif  /* CORRETOR_H */
