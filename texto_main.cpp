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
        cout << "-" << palavra << "-" << endl;

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
