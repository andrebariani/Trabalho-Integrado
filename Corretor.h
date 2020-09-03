/*! \file Corretor.h
    \brief Classe Corretor e funções relacionadas
 *  \author Mariane Lamas Malheiros
 *  \author André Matheus Bariani Trava
 *  Created on 3 de Agosto de 2018, 15:36
*/
/*! \class Corretor
    \brief Classe execução do Corretor
*/

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
    	Texto texto;   ///< Classe Texto
    	Dicionario dic;///< Classe Dicionário
        typedef struct {
            wstring palavra; ///< String da palavra errada
            int contador; ///< Contador de número de vezes que erro aparece no texto
        } erros; ///< Struct da palavra errada
        forward_list<erros> wrongWords; ///< Lista de palavras erradas

        /// Correção de uma palavra por uma nova palavra
        /** Inicia função que corrige uma palavra por uma nova palavra inserida.*/
        void corrigir();

        /// Apresentar Erro
        /** Apresenta a palavra errada encontrada no Texto.*/
        void apresentarErro(Palavra palavraErrada);

        /// Selecionar Palavra Semelhante
        /** Recebe a palavra errada e retorna uma palavra dentre as sugestão de palavras semelhantes*/
        Palavra selecPalavraSemelhante(Palavra palavraErrada);

        /// Adicionar Palavra Dicionario
        /** Recebe palavra errada e adiciona no objeto membro Dicionario dic.*/
        void adicionarPalavraDicionario(Palavra palavraErrada);

        /// Adicionar Erro
        /** Recebe palavra errada e adiciona na lista de palavras erradas.*/
        void adicionarErro(Palavra palavraErrada);

        /// Exibir
        /** Exibe a lista de palavras erradas.*/
        void exibirErros();

    public:
        /// Construtor
        /** Inicializa o Corretor com o nome do arquivo de texto para corrigir.*/
        Corretor(std::string nometexto/**< [in] Nome do arquivo.*/);

        /// Inicializador da Correção
        /** Inicia o processo de correção do texto.*/
        void iniciarCorrecao();
};


#endif  /* CORRETOR_H */
