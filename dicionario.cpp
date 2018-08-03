#include "Dicionario.h"

Dicionario::Dicionario()
{
    cont = 0; //Number of words

    //Cria um objeto ifstream "file"
    ifstream file;

    //Abre o arquivo no modo "in" que permite apenas leitura
    file.open("dict.txt", std::ifstream::in);

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
            std::cout << "ERROR" << std::endl;
        }

    //Fecha o arquivo
    file.close();
}

void Dicionario::limparArquivo()
{
    ifstream file;

    //Abre o arquivo no modo "trunc" para limpar o arquivo
    file.open("dict.txt", std::ifstream::in |  std::ifstream::trunc);
    
    //Fecha o arquivo    
    file.close();
}

void Dicionario::atualizarArquivo()
{
    ofstream file;

    //Abre o arquivo no modo "out", para escrever e o "app" para que escreva no fim do arquivo
    file.open("dict.txt", std::ofstream::out | std::ofstream::app);

    for(int i = 0; i < cont; i++)
    {
        file << palavra << std::endl;
    }

    //Fecha o arquivo
    file.close();
}

Palavra * Dicionario::buscaSemelhante(Palavra p)
{
    Palavra * It = arvore.busca(p);
    Palavra * Inicio = It;
    int i = 0;

    while(It -> semelhantes(p))
    {
            Semelhantes[i] = *It;
            i++;
            It++;
    } 

    return Inicio;
}