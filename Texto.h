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
        Texto( string na = "nomearq.txt" );
        //void carregarArquivo(string na);
        /*Palavra*/string percorrerTexto();
        void corrigirPalavra( int pos_atual, /*Palavra*/string corrigida );
        void salvarArquivo();
};

#endif /* TEXTO_H */

