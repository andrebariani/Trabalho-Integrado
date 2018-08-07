#include "Dicionario.h"
using namespace std;

dicionario::dicionario()
{
    //Cria um objeto wifstream "file"
    wifstream file;

    //Abre o arquivo no modo "in" que permite apenas leitura
    file.open("dict.txt", wifstream::in);

        //"is_open" retorna TRUE se o "file" está aberto
        //"good" retorna TRUE se abriu sem problemas
        if(file.is_open() && file.good())
        {
            Palavra p;
            wstring s;

            //"file" envia seu conteúdo para "dict" 
            while(getline(file, s));   //Salva a palavra do arquivo para s
            {
                if(arvore.getQtd() <= 10000)
                {
                    p.setPalavra(s);    //Passa palavra para p
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
    //Chama processo de inserção da arvore
    arvore.insere(p);
}

void dicionario::remover(Palavra p)
{
    //Chama processo de remoção da arvore
    arvore.remove(p);
}

queue<Palavra> * dicionario::buscaSemelhante(Palavra p)
{
    queue<Palavra> *semelhantes = new queue<Palavra>;

    wstring menor = L"";
    wstring maior = L"";
    menor = p.getPalavra[1] + p.getPalavra[2];
    maior = p.getPalavra[1] + (p.getPalavra[2] + 1);

    arvore.buscaIntervalo(*semelhantes, menor, maior);
    
    if((semelhantes -> back).semelhantes(p))
    {
        return semelhantes;
    }

}