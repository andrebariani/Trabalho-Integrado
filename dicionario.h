#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

#include "Arvore.h"
#include "Palavra.h"

using namespace std;

class dicionario
{
    private:
        Arvore<Palavra> arvore;
        int cont;

    public:

        //Construtor:
        //Coloca as palavras do arquivo na árvore de palavras
        dicionario();

        void limparArquivo();

        //Salva a árvore de palavras no arquivo
        void atualizarArquivo();

        ////Retorna primeiro elemento do vetor de palavras semelhantes
        //NO * buscaSemelhante(Palavra p);

        void incluir(Palavra p);

        void remover(Palavra p);

        bool buscaPalavra(Palavra p);

        queue<Palavra> & buscaSemelhante(Palavra p, queue<Palavra> & queueSemelhante);

        void printar();
};
#endif 