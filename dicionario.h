#include <iostream>
#include <fstream>
#include <cstring>

class dicionario
{
    private:
        Palavra dict[10000];

        int cont;
    private:

        //Constructor:

        dicionario()

        //Functions:

        void consulta(arq dict, Palavra p);
        void inclusao(arq dict, Palavra p);
        void atualizarArquivo();
};