#include "Dicionario.h"
using namespace std;

dicionario::dicionario()
{
    cont = 0; //Number of words

    //Cria um objeto wifstream "file"
    wifstream file;

    //Abre o arquivo no modo "in" que permite apenas leitura
    file.open("dict.txt", wifstream::in);

        //"is_open" retorna TRUE se o "file" está aberto
        //"good" retorna TRUE se abriu sem problemas
        if(file.is_open() && file.good())
        {
            Palavra p;

            //"file" envia seu conteúdo para "dict" 
            while(!file.fail()) //"fail" retorna 1 quando o arquivo acaba
            {    
                if(arvore.getQtd() < 10000)
                {
                    file >> p; //Passa palavra para p
                    arvore.insere(p);   //Adiciona p na arvore
                }
                else
                {
                    //ERRO
                    //Passou limite
                }
            }
        }
        else
        {
            cout << "ERROR" << endl;
        }

    //Fecha o arquivo
    file.close();
}

void dicionario::limparArquivo()
{
    wifstream file;

    //Abre o arquivo no modo "trunc" para limpar o arquivo
    file.open("dict.txt", wifstream::in |  wifstream::trunc);
    
    //Fecha o arquivo    
    file.close();
}

void dicionario::atualizarArquivo(Palavra p)
{
    wofstream file;

    //Abre o arquivo no modo "out", para escrever e o "app" para que escreva no fim do arquivo
    file.open("dict.txt", wofstream::out | wofstream::app);

    //Adiciona a palavra do Nó em questão no arquivo
    file << p << endl;

    //Fecha o arquivo
    file.close();
}

void dicionario::incluir(Palavra p)
{
    arvore.insere(p);
}

void dicionario::remover(Palavra p)
{
    arvore.remove(p);
}