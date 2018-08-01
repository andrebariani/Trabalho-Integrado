#include "Texto.h"
#include "Palavra.h"
using namespace std;

int Texto::pos_atual = -1;
int Texto::size = 0;

Texto::Texto( string na ) {
    texto = new Palavra[10000];
    nomearq = na;
    string p;

    ifstream arq(nomearq + ".txt");

    while(arq >> p) {
        if( size > 10000 )
            break;
        texto[size++].setPalavra(p);
    }

    arq.close();
}

Palavra Texto::percorrerTexto() {

    Palavra pal;

    if(++pos_atual > size) {
        return pal;
    }

    return texto[pos_atual];
}

void Texto::corrigirPalavra( Palavra corrigida ) {
    texto[pos_atual] = corrigida;
}

void Texto:: salvarArquivo() {
    string n = nomearq + "-Copy.txt";
    ofstream arq( n );

    int i=0;
    while( i <= size ) {
        arq << texto[i++];
        arq << " ";
    }

    cout << "Arquivo Salvo" << endl;

}
