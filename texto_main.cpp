#include <cstdlib>
#include "Texto.h"
#include "Palavra.h"

using namespace std;

int main(int argc, char** argv) {

    // setlocale(LC_ALL, "portuguese-brazilian");

    Palavra palavra;

    cout << "Insira nome do arquivo texto: " << endl;

    string arq;
    cin >> arq;

    try {
        Texto txt(arq);

        palavra = txt.percorrerTexto();
        // palavra.setPalavra(txt.percorrerTexto().getPalavra());

        Palavra Null;

        while(!(palavra == Null)) {
            Palavra pa = txt.getPalavraAnterior();
            if(!(pa == Null)) {
                wcout << "Anterior: -" << pa.minuscula().getPalavra()  << "-" << endl;
            }

            Palavra pmin = palavra.minuscula();
            wcout << "Atual: -" << pmin << "-" << endl;

            Palavra pp = txt.getPalavraProximo();
            if(!(pp == Null)) {
                Palavra ppmin = pp.minuscula();
                wcout << "Proximo: -" << ppmin << "-" << endl;
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
    } catch( std::exception &e ) {
                cout << "ERRO! " << e.what() << endl;
                return -1;
    }
}
