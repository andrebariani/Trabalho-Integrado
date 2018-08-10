#ifndef CORRETOR_H
#define CORRETOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include "Palavra.h"
#include "Texto.h"
#include "Dicionario.h"

using namespace std;

class Corretor {
    private:
    	Texto texto;
    	Dicionario dic;
        typedef struct {
            wstring palavra;
            int contador;
        } erros;
        forward_list<erros> wrongWords;
        void iniciarCorrecao(); // Inicia processo de correção do arquivo de texto inteiro
        void apresentarErro(Palavra palavraErrada);
        Palavra selecPalavraSemelhante(Palavra palavraErrada);
        void adicionarPalavraDicionario(Palavra palavraErrada);
        void adicionarErro(Palavra palavraErrada);
        void exibirErros();

    public:
        Corretor(std::string nometexto);
        // void mudarTexto( string nome_texto );
        void corrigir();
    	// void apresentarErro();
    	// void corrigir();// usar uma palavra fornecida pelo dicionário para corrigir uma palavra errada no texto
    	// void ignorar();//ignorar um erro encontrado pelo corretor e não fazer mais nada
};


#endif  /* CORRETOR_H */
