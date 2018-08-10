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

class Dicionario
{
    private:
        Arvore<Palavra> arvore;

        ///Limpar arquivo
        /** 
         * Exclui tudo que está no arquivo dict.txt
         * Usada apenas antes da chamada da função atualizarArquivo*/
        void limparArquivo();

    public:

        ///Construtor:
        /** Coloca as palavras do arquivo na árvore de palavras*/
        Dicionario();

        ///Destrutor:
        /** Salva as palavras da arvore no arquivo e destroi o dicionario*/
        ~Dicionario();

        ///Atualizar arquivo
        /** Salva a árvore de palavras no arquivo*/
        void atualizarArquivo();

        ///Incluir
        /**
         * Adiciona a palavra p na árvore de palavras
         * @param   p                   palavra a ser inserida*/
        void incluir(Palavra p);

        ///Remover
        /**
         * Remove a palavra p da árvore de palavra
         * @param   p                   palavra a ser removida*/
        void remover(Palavra p);

        ///Busca palavra
        /**
         * @param   p                   palavra a ser procurada
         * @return                      true caso a palavra p exista na árvore, false caso o contrário*/
        
        bool buscaPalavra(Palavra p);

        /**
         * Recebe uma fila de palavras e retorna essa fila com apenas palavras que sejam semelhantes a p e pertencem à árvore
         * @param   p                   palavra base
         * @param   queueSemelhante     fila de palavras a ser preenchida por palavras semelhantes a p e pertencentes à árvore*/
        queue<Palavra> & buscaSemelhante(Palavra p, queue<Palavra> & queueSemelhante);
};
#endif 