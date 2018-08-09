#include <iostream>
#include "dicionario.h"
using namespace std;

int main()
{
    dicionario dict;
    Palavra p;
    queue<Palavra> fila; 
    p.setPalavra(L"esse");
    dict.incluir(p);
    p.setPalavra(L"teste");
    dict.incluir(p);
    p.setPalavra(L"deu");
    dict.incluir(p);
    p.setPalavra(L"certo");
    dict.incluir(p);
    dict.printar();
    p.setPalavra(L"delco");
    dict.buscaSemelhante(p, fila);
    dict.atualizarArquivo();

    return 0;
}