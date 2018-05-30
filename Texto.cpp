#include "Texto.h"
using namespace std;

int Texto::pos_atual = -1;
int Texto::size = 0;

Texto::Texto( string na ) {
    p = new string[10000];
    string palavra;
    string ext = ".txt";
    nomearq = na + ext;
    
    //strcat(na, test);
    ifstream arq(nomearq);
    
    while(arq >> palavra) {
        if( size > 10000 )
            break;
        
        p[size++] = palavra;
        
    }
    
    arq.close();
}

/*Palavra*/string Texto::percorrerTexto() {
    
    if(++pos_atual > size) {
        return "";
    }
    
    return p[pos_atual];
}

void Texto::corrigirPalavra( int pos_atual, /*Palavra*/string corrigida ) {
    p[pos_atual] = corrigida;
}

void Texto:: salvarArquivo() {
    string n = nomearq + "-Copy.txt";
    ofstream arq( n );
    
    int i=0;
    while( i <= size ) {
        arq << p[i++];
        arq << " ";
    }
    
    cout << "Arquivo Salvo" << endl;
    
}
