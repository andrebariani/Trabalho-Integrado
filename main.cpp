#include <locale>
#include <string>
#include <iostream>

// #include "Corretor.h"
// #include "dicionario.h"
#include "Texto.h"
#include "Palavra.h"

enum {SAIR, CARREGATEXTO, CORRIGI};

int main() {

    string nome_texto;

    printf( "\t**Corretor Ortográfico (v1.0)**\t\t\t\n");

    int op;

    while(1) {
        printf("\t\tInsira Opção:\t\t\t\t\t\t\n");
        printf("1 - Carregar Texto:\t\t\t\t\t\t\n");
        printf("2 - Iniciar Correção:\t\t\t\t\t\t\n");
        printf("0 - Sair:\t\t\t\t\t\t\n");

        cout << ">>" ;
        cin >> op;

        try {
            switch (op) {
                case SAIR:
                    cout << "Bye!" << endl;
                    return 0;
                break;
                case CARREGATEXTO: {
                    printf("\tInsira Nome do arquivo de texto\t\t\t\n");
                    cout << ">>" ;
                    cin >> nome_texto;
                }
                break;
                case CORRIGI: {
                    Texto txt(nome_texto);
                    // dicionario dic(nome_dic);
                    // Rest of code
                }
                break;
            }
        } catch( std::exception &e ) {
            cout << "ERRO! " << e.what() << endl;
            continue;
        }
    }
    return 0;
}
