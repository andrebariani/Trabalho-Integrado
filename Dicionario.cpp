#include "Dicionario.h"
#include "Arvore.h"
#include "Palavra.h"
using namespace std;

///Adicionar arquivo
/**
 * Método que adiciona a palavra p ao arquivo dict.txt
 * @param   p   palavra a ser adicionada ao arquivo*/
void adicionarArquivo(Palavra p)
{
    setlocale(LC_ALL,"pt_BR.UTF-8");

    wofstream file;

    //Abre o arquivo no modo "out", para escrever e o "app" para que escreva no fim do arquivo
    file.open("dict.txt", wofstream::out | wofstream::app);

    //Caso o arquivo não seja aberto ou ocorra um erro na abertura do mesmo
    if(!(file.is_open() && file.good()))
    {
        throw runtime_error("Erro ao abrir o arquivo\n"); //Tratamento de excessão
    }

    //Adiciona a palavra do Nó em questão no arquivo
    file << p << endl;

    //Fecha o arquivo
    file.close();
}

///Construtor
/** cria um arquivo que possui uma árvore de palavras extraidas do arquivo dict.txt*/
Dicionario::Dicionario()
{
    setlocale(LC_ALL,"pt_BR.UTF-8");

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
            try{
                //Adiciona p na Arvore
                arvore.insere(p);
            }catch(bad_alloc){
            }
        }
    }

    //Fecha o arquivo
    file.close();
}

///Destrutor:
/** Salva as palavras da arvore no arquivo*/
Dicionario::~Dicionario()
{
    atualizarArquivo();
}

///limparArquivo
/** Exclui todo o conteúdo do arquivo dict.txt*/
void Dicionario::limparArquivo()
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

///Incluir
/** Inclui a palavra p na árvore de palavras*/
bool Dicionario::incluir(Palavra p)
{
    try{
        //Chama processo de inserção da arvore
        arvore.insere(p);
        return true;
    }catch(bad_alloc){
        return false;
    }
}

///Remover
/** Remove a palavra p da árvore de palavras*/
void Dicionario::remover(Palavra p)
{
    //Chama processo de remoção da arvore
    arvore.remove(p);
}

///Buscar palavra
/** Retorna TRUE caso p pertença a árvore de palavras, FALSE caso contrário*/
bool Dicionario::buscaPalavra(Palavra p)
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

///Busca semelhante
/** Retorna uma fila de palavras que sejam semelhantes a p e pertençam à árvore de palavras*/
queue<Palavra> & Dicionario::buscaSemelhante(Palavra p, queue<Palavra> & queueSemelhante)
{
    Palavra menor;
    Palavra maior;
    wstring aux0;
    wstring aux1;
    menor.setPalavra(p.getPalavra().substr(0, 2));
    aux0 = p.getPalavra()[0];
    aux1 = ((p.getPalavra())[1] + 1);
    aux0.append(aux1);
    maior.setPalavra(aux0);
    //Esvaziando a queue
    while(!queueSemelhante.empty())
        queueSemelhante.pop();

    //Pegando elementos semelhantes a p
    arvore.buscaIntervalo(queueSemelhante, menor, maior);
    if(!queueSemelhante.empty())
    {
        //Se o último elemento da fila não for semelhante a p
        if(!(queueSemelhante.back().semelhantes(p)))
        {
            int qSize = queueSemelhante.size() - 1;
            //Passa todos os valores menos o último de semelhantes para temp
            for(int i = 0; i < qSize; i++)
            {
                queueSemelhante.push(queueSemelhante.front());
                queueSemelhante.pop();
            }

            //Troca os conteúdos entre temp e semelhantes
            queueSemelhante.pop(); //Tira o último elemento de queueSemelhante
        }
    }
    return queueSemelhante;

}

///Atualizar arquivo
/** Salva todas as palavras pertencentes à árvore no arquivo em branco dict.txt*/
void Dicionario::atualizarArquivo()
{
    cout << "Atualizando Dicionário..." << endl;
    limparArquivo(); //Limpa o arquivo
    arvore.percursoEmOrdem( adicionarArquivo ); //Coloca a arvore no arquivo em EmOrdem
    cout << "Dicionário salvo!" << "\n\n";
}
