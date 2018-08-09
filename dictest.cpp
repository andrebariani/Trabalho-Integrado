#include <iostream>
#include "dicionario.h"

int main()
{
    dicionario dict;

    Palavra p;
    p.setPalavra(L"KKKK");
    dict.remover(p);
    dict.atualizarArquivo(p);

    return 0;
}