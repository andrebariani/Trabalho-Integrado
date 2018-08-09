#include "Dicionario.h"
#include "Arvore.h"
#include "Palavra.h"
using namespace std;

void printPalavra(Palavra p)
{
    wcout << p <<"\t";
}

void adicionarArquivo(Palavra p)
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
        while(file >> s)   //Salva a palavra do arquivo para s
        {
            p.setPalavra(s);    //Passa palavra para p
            arvore.insere(p);   //Adiciona p na arvore
        }      
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
        throw runtime_error("Erro ao abrir o arquivo\n"); //Tratamento de excessão
    }

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

bool dicionario::buscaPalavra(Palavra p)
{
    //Se encontrar, return true
    if(arvore.busca(p))
    {
        return true;
    }
    //Se não, retorna false
    else
    {
        return false;
    }
}

queue<Palavra> & dicionario::buscaSemelhante(Palavra p, queue<Palavra> & queueSemelhante)
{
    Palavra menor;
    Palavra maior;
    wstring aux;
    menor.setPalavra(p.getPalavra().substr(0, 2));
    aux = (p.getPalavra())[0] + ((p.getPalavra())[1] + 1);
    maior.setPalavra(aux);

    //Esvaziando a queue
     while(!queueSemelhante.empty())
    {
        queueSemelhante.pop();
    }

    //Pegando elementos semelhantes a p
    arvore.buscaIntervalo(queueSemelhante, menor, maior);

    //Se o último elemento da fila não for semelhante a p
    if(!((queueSemelhante.back()).semelhantes(p)))
    {
        queue<Palavra> temp;

        //Passa todos os valores menos o último de semelhantes para temp
        for(int i = 0; i < (queueSemelhante.size() - 1); i++)
        {
            temp.push(queueSemelhante.front());
            queueSemelhante.pop();
        }

        //Troca os conteúdos entre temp e semelhantes
        queueSemelhante.pop(); //Tira o último elemento de queueSemelhante

        //Passa os elementos de temp para queueSemelhante
        for(int i = 0; i < temp.size(); i++)
        {
            queueSemelhante.push(temp.front());
            temp.pop();
        }
    }

    return queueSemelhante;

}

void dicionario::printar()
{
    arvore.percursoEmOrdem( printPalavra ); //Imprime a arvore em EmOrdem
}

void dicionario::atualizarArquivo()
{
    limparArquivo(); //Limpa o arquivo
    arvore.percursoEmOrdem( adicionarArquivo ); //Coloca a arvore no arquivo em EmOrdem
}