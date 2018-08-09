#include <iostream>
#include "dicionario.h"
using namespace std;

int main()
{
    dicionario dict;
    Palavra p;
    
    p.setPalavra(L"esse");
    dict.incluir(p);
    p.setPalavra(L"teste");
    dict.incluir(p);
    p.setPalavra(L"deu");
    dict.incluir(p);
    p.setPalavra(L"certo");
    dict.incluir(p);
    dict.printar();
    dict.limparArquivo();
    dict.atualizarArquivo();

    return 0;
}