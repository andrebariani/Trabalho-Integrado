#include <cstdlib>
#include "Texto.h"
#include "Palavra.h"

using namespace std;

int main(int argc, char** argv) {

    Texto txt("texto");

    Palavra palavra;

    palavra = txt.percorrerTexto();
    // palavra.setPalavra(txt.percorrerTexto().getPalavra());

    Palavra Null;

    while(!(palavra == Null)) {
        // Palavra pa = txt.getPalavraAnterior();
        // if(!(pa == Null)) {
        // cout << "Anterior: -" << pa << "-" << endl;
        // }

        cout << "Atual: -" << palavra << "-" << endl;

        // Palavra pp = txt.getPalavraProximo();
        // if(!(pp == Null)) {
        // // cout << "Proximo: -" << txt.getPalavraProximo() << "-" << endl;
        // cout << "Proximo: -" << pp << "-" << endl;
        // }

        cout << "Trocar palavra?" << endl;

        char y;
        cin >> y;

        if(y == 's') {
            cout << "Trocar por qual palavra?" << '\n';

            Palavra p;

            cin >> p;

            txt.corrigirPalavra(p);

        }

        palavra = txt.percorrerTexto();
        // palavra.setPalavra(txt.percorrerTexto().getPalavra());
    }

    txt.salvarArquivo();

}
