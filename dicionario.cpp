#include "Dicionario.h"
#include "Arvore.h"
#include "Palavra.h"
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
                    throw runtime_error("Árvore cheia\n"); //Tratamento de excessão
                }  
            }
        }
        else
        {
            throw runtime_error("1 Erro ao abrir o arquivo\n"); //Tratamento de excessão
        }

    //Fecha o arquivo
    file.close();
}

void dicionario::limparArquivo()
{
    wofstream file;

    //Abre o arquivo no modo "trunc" para limpar o arquivo
    file.open("dict.txt", wofstream::in |  wofstream::trunc);
    if(!file.is_open() && !file.good())
    {
        throw runtime_error("2 Erro ao abrir o arquivo\n"); //Tratamento de excessão
    }
    
    //Fecha o arquivo    
    file.close();
}

void dicionario::atualizarArquivo(Palavra p)
{
    wofstream file;

    //Abre o arquivo no modo "out", para escrever e o "app" para que escreva no fim do arquivo
    file.open("dict.txt", wofstream::out | wofstream::app);
   
    if(!(file.is_open() && file.good()))
    {
        throw runtime_error("Erro ao abrir o arquivo\n"); //Tratamento de excessão
    }

    //Adiciona a palavra do Nó em questão no arquivo
    file << p << endl;

    //Fecha o arquivo
    file.close();
}

void dicionario::incluir(Palavra p)
{
    //Chama processo de inserção da arvore
    if(arvore.getQtd() < 10000)
    {
        arvore.insere(p);
    }
    else   
    {
        throw runtime_error("Árvore cheia\n"); //Tratamento de excessão
    }
}

void dicionario::remover(Palavra p)
{
    wcout << arvore.getQtd() << endl;
    //Chama processo de remoção da arvore
    if(arvore.getQtd() > 1)
    {
        arvore.remove(p);
    }
    else
    {
        throw runtime_error("Árvore vazia\n"); //Tratamento de excessão
    }
}

bool dicionario::buscaPalavra(Palavra p)
{
    if(arvore.busca(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

queue<Palavra> * dicionario::buscaSemelhante(Palavra p)
{
    queue<Palavra> *queueSemelhante= new queue<Palavra>;

    Palavra menor;
    Palavra maior;
    wstring aux;
    menor.setPalavra(p.getPalavra().substr(0, 2));  
    aux = (p.getPalavra())[0] + ((p.getPalavra())[1] + 1);
    maior.setPalavra(aux);

    arvore.buscaIntervalo(*queueSemelhante, menor, maior);
    
    if(queueSemelhante-> empty())
    {
        throw runtime_error("Não há palavras semelhantes\n"); //Tratamento de excessão
    }

    //Se o último elemento da fila não for semelhante a p
    if(!((queueSemelhante -> back()).semelhantes(p))) 
    {
        queue<Palavra> temp;

        //Passa todos os valores menos o último de semelhantes para temp 
        for(int i = 0; i < (queueSemelhante -> size() - 1); i++)
        {
            temp.push(queueSemelhante-> front());
            queueSemelhante -> pop();
        }

        //Troca os conteúdos entre temp e semelhantes
        //queueSemelhante -> swap(temp);
        queueSemelhante -> pop();

        for(int i = 0; i < (temp.size()); i++)
        {
            queueSemelhante -> push(temp.front());
            temp.pop();
        }
    }   
    
    return queueSemelhante;    

}
