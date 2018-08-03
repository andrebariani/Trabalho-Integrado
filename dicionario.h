#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Arvore.h"
#include "Palavra.h"

class dicionario
{
    private:
        std::vector<Palavra> Semelhantes;
        Arvore<Palavra> arvore;
        int cont;

    public:

        //Construtor:
        //Coloca as palavras do arquivo na árvore de palavras
        dicionario();

        //Salva a árvore de palavras no arquivo
        void atualizarArquivo();

        //Retorna primeiro elemento do vetor de palavras semelhantes
        Palavra * buscaSemelhante(Palavra p);

};