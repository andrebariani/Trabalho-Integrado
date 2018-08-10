/*! \file dicionario.h
    \brief Classe dicionario
 *  \author Thiago Yussuki Uehara
 *  Created on 30 de Maio de 2018, 15:01
*/

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

        //Exclui tudo que está no arquivo dict.txt
        //Usada apenas antes da chamada da função atualizarArquivo
        void limparArquivo();

    public:

        //Construtor:
        //Coloca as palavras do arquivo na árvore de palavras
        dicionario();

        //Salva a árvore de palavras no arquivo
        void atualizarArquivo();

        //Adiciona a palavra p na árvore de palavras
        // Parâmetro p, palavra a ser inserida
        void incluir(Palavra p);

        //Remove a palavra p da árvore de palavras
        // Parâmetro p, palavra a ser removida
        void remover(Palavra p);

        //Retorna true caso a palavra p exista na árvore, false caso o contrário
        //Parâmetro p, palavra a ser procurada
        bool buscaPalavra(Palavra p);

        //Recebe uma fila de palavras e retorna essa fila com apenas palavras que sejam semelhantes a p e pertencem à árvore
        // Parâmetro p, palavra base
        // Parâmetro & queueSemelhante, fila de palavras a ser preenchida por palavras semelhantes a p e pertencentes à árvore
        queue<Palavra> & buscaSemelhante(Palavra p, queue<Palavra> & queueSemelhante);
};
#endif 