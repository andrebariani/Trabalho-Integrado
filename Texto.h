#ifndef TEXTO_H
#define TEXTO_H

#include <fstream>
#include <iostream>
#include <string>

#include "Palavra.h"

using namespace std;

class Texto {

    private:
        Palavra *texto;
        // Nome do arquivo do texto original
        string nomearq;
        static int pos_atual;
        static int size;

    public:
        Texto( string na = "nomearq.txt" );
        Palavra percorrerTexto();
        void corrigirPalavra( Palavra corrigida );
        void salvarArquivo();
};

#endif /* TEXTO_H */
