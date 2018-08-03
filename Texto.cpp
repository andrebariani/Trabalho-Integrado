#include "Texto.h"
#include "Palavra.h"
using namespace std;

int Texto::pos_atual = -1;
int Texto::t_size = 0;
int Texto::d_size = 0;
int Texto::total_size = 0;

Texto::Texto( string na ) {
    texto = new Palavra[10000];
    delim = new string[10000];
    nomearq = na;
    string p = "";
    string d = "";

    size_t found = nomearq.find(".txt");

    if(found == std::string::npos) {
        cout << ".txt not found" << endl;
        nomearq = nomearq + ".txt";
    }

    cout << nomearq << endl;
    ifstream arq(nomearq);

    char c;

    while(arq.get(c)) {
        if(total_size > 10000) // Atingiu o tamanho máximo do vetor
            break;

        switch (isalpha(c)) {
            case 0: // Se não
            cout << "Delim Found: " << c << endl;
            if(p == "") {
                d = d + c;
                cout << "-" << d << "-"<< endl;
            }
            else {
                texto[t_size++].setPalavra(p);
                p = "";
                d = d + c;
            }
            break;
            default: // Se o caracter for Letra
                cout << "Letter Found: " << c << endl;
                if(d == "") {
                    p = p + c;
                    cout << p << endl;
                }
                else {
                    delim[d_size++] = d;
                    d = "";
                    p = p + c;
                }
            break;
        }
        ++total_size;
    }

    // Por causa do salvarArquivo(), esse trecho é necessário para pegar a última pontuação
    // Não é necessário para o vetor texto pois todo arquivo .txt termina com '\n'
    if(d != "")
        delim[d_size++] = d;

    cout << t_size << endl;
    cout << d_size << endl;
    cout << total_size << endl;
    arq.close();
}

Palavra Texto::percorrerTexto() {

    Palavra pal;

    if(++pos_atual > t_size) {
        return pal;
    }

    return texto[pos_atual];
}

Palavra Texto::getAnterior() {
    Palavra pal;

    if( pos_atual != 0 )
        return texto[pos_atual - 1];
    return pal;
}

Palavra Texto::getProximo() {
    Palavra pal;

    if( pos_atual+1 < t_size )
        return texto[pos_atual + 1];
    return pal;
}

void Texto::corrigirPalavra( Palavra corrigida ) {
    texto[pos_atual] = corrigida;
}

void Texto:: salvarArquivo() {
    size_t found = nomearq.find(".txt");

    string n = "Copy-" + nomearq;
    ofstream arq( n );

    int i = 0, j = 0, k = 0;
    while( k++ < total_size ) {
        if( i < t_size )
            arq << texto[i++];
        if( j < d_size )
            arq << delim[j++];
    }

    cout << "Arquivo Salvo" << endl;

}
