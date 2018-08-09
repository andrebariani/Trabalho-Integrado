#include <locale>
#include <string>
#include <iostream>

#include "Corretor.h"

enum {SAIR, CARREGATEXTO, CORRIGIR};

int main() {

    // $ g++ -o main_exe main.cpp Texto.cpp Palavra.cpp dicionario.cpp Corretor.cpp

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
                case CORRIGIR: {
                    printf("\tIniciando Correção...\t\t\t\n");

                    Corretor corretor(nome_texto);

                    corretor.iniciarCorrecao();

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
