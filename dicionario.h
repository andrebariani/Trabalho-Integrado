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

        void consulta(Palavra p);
        void inclusao(Palavra p);
        void atualizarArquivo();

        //Just for tests

        void printar();
};