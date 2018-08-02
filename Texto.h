/*! \file Texto.h
    \brief Classe texto e funções relacionadas
 *  Autor: André Matheus Bariani Trava
 *  Created on 30 de Maio de 2018, 14:35
*/
/*! \class Texto
    \brief Classe de manipulação de um texto
*/

#ifndef TEXTO_H
#define TEXTO_H

#include <fstream>
#include <iostream>
#include <string>

#include "Palavra.h"

using namespace std;

class Texto {

    public:
        /// Construtor de Texto

        /** Recebe uma string que corresponde ao nome do arquivo do texto a ser carregado ao programa */
        Texto( string na = "nomearq" /**< [in] nome do arquivo a ser carregado. O arquivo pode ou não conter
                                        a extensão ".txt". Por padrão, "nomearq". */);

        /// Percurso do Texto
        /** Retorna uma Palavra do texto em ordem de chamada dessa função */
        Palavra percorrerTexto();

        /// Correção da palavra do Texto
        /** Recebe uma palavra e substitui a palavra do Texto */
        void corrigirPalavra( Palavra corrigida /** < [in] Palavra correta que troca com a palavra do texto */ );

        /// Armazenamento do novo texto
        /** Salva o texto em um novo arquivo com extensão ".txt" com as palavras corrigidas */
        void salvarArquivo();

        void Palavra getAnterior();

        void Palavra getProximo();


    private:
        Palavra *texto; /// Vetor contendo todas as palavras do texto
        string *delim; /// Vetor de delimitadores do Texto (tudo que não for palavra)
        string nomearq; /// nome do arquivo original
        static int pos_atual; /// Posição atual do vetor de palavras do texto. Valor é incrementado com toda a chamada de percorrerTexto()
        static int total_size;
        static int t_size; /// Tamanho do vetor de palavras do Texto
        static int d_size; /// Tamanho do vetor de delimitadores do Texto
};

#endif /* TEXTO_H */
