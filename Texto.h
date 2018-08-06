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
#include <cwchar>
#include <vector>
#include <locale.h>
#include <locale>

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

        /// Pegar palavra anterior
        /** Retorna palavra anterior à palavra atual  */
        Palavra getPalavraAnterior();

        /// Pegar palavra superior
        /** Retorna palavra superior à palavra atual  */
        Palavra getPalavraProximo();

        // int isAcento(wchar_t c);

    private:
        vector<Palavra> palavras; /// Vetor contendo todas as palavras do texto
        vector<wstring> delim; /// Vetor de delimitadores do Texto (tudo que não for palavra)
        string nomearq; /// nome do arquivo original
        vector<Palavra>::iterator it_palavras; /// Iterador do vetor de palavras do texto.
        bool word_first_flag; /// Flag que identfica se a primeira string de um arquivo é um delimitador ou palavra
        int total_size;
};

#endif /* TEXTO_H */
