#include <cstdlib>
#include "Texto.h"
#include "Palavra.h"

using namespace std;

int main(int argc, char** argv) {

    // setlocale(LC_ALL, "portuguese-brazilian");
    Texto txt("texto");

    Palavra palavra;

    palavra = txt.percorrerTexto();
    // palavra.setPalavra(txt.percorrerTexto().getPalavra());

    Palavra Null;

    while(!(palavra == Null)) {
        Palavra pa = txt.getPalavraAnterior();
        if(!(pa == Null)) {
        wcout << "Anterior: -" << pa << "-" << endl;
        }

        wcout << "Atual: -" << palavra << "-" << endl;

        Palavra pp = txt.getPalavraProximo();
        if(!(pp == Null)) {
        // cout << "Proximo: -" << txt.getPalavraProximo() << "-" << endl;
        wcout << "Proximo: -" << pp << "-" << endl;
        }

        cout << "Trocar palavra?" << endl;

        char y;
        cin >> y;

        if(y == 's') {
            cout << "Trocar por qual palavra?" << '\n';

            Palavra p;

            wcin >> p;

            txt.corrigirPalavra(p);

        }

        palavra = txt.percorrerTexto();
        // palavra.setPalavra(txt.percorrerTexto().getPalavra());
    }

    txt.salvarArquivo();

}
