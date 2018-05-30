/*! \class Texto
\brief Classe de manipulação de Texto
*/

#ifndef TEXTO_H
#define TEXTO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Texto {

    private:
        /*Palavra*/string *p;
        // Nome do arquivo do texto original
        string nomearq;
        static int pos_atual;
        static int size;

    public:
        /// Construtor de Texto
        /** Recebe o nome do arquivo .txt para carregar */
        Texto( string na = "nomearq.txt" /**< [in] Nome do arquivo para carregar. Por padrão, "nomearq.txt". */);

        //void carregarArquivo(string na);

        /// Percorrer Texto
        /** Retorna uma palavra do texto (iniciando com a primeira palavra), e ao ser chamado de novo retorna a proxima palavra do texto */
        /*Palavra*/string percorrerTexto();


        /// Corrije Palavra
        /** Recebe a palavra corrijida e substiui a palavra do texto */
        void corrigirPalavra( /*Palavra*/string corrigida /**< [in] Palavra para substituir do texto.*/);

        /// Salva Texto
        /** Salva Texto em um arquivo com o mesmo nome e um "-Copy" no final */
        void salvarTexto();
};

#endif /* TEXTO_H */
