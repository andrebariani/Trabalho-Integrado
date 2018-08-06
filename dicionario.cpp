#include "Dicionario.h"
using namespace std;

dicionario::dicionario()
{
    cont = 0; //Number of words

    //Cria um objeto ifstream "file"
    ifstream file;

    //Abre o arquivo no modo "in" que permite apenas leitura
    file.open("dict.txt", ifstream::in);

        //"is_open" retorna TRUE se o "file" está aberto
        //"good" retorna TRUE se abriu sem problemas
        if(file.is_open() && file.good())
        {
            Palavra p;
            string s;
            //"file" envia seu conteúdo para "dict" 
            while(!file.fail()) //"fail" retorna 1 quando o arquivo acaba
            {
                file >> s;
                p.setPalavra(s);
                cont++;
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
    ifstream file;

    //Abre o arquivo no modo "trunc" para limpar o arquivo
    file.open("dict.txt", ifstream::in |  ifstream::trunc);
    
    //Fecha o arquivo    
    file.close();
}

void dicionario::atualizarArquivo()
{
    ofstream file;

    //Abre o arquivo no modo "out", para escrever e o "app" para que escreva no fim do arquivo
    file.open("dict.txt", ofstream::out | ofstream::app);

    for(int i = 0; i < cont; i++)
    {
        file << palavra << endl;
    }

    //Fecha o arquivo
    file.close();
}

void incluir(Palavra p)
{
    arvore.insere(p);
}