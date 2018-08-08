#include <locale>
#include <string>
#include <iostream>

#include "Corretor.h"
#include "dicionario.h"
#include "Texto.h"
#include "Palavra.h"

enum {SAIR, CARREGATEXTO, CARREGADIC, CORRIGI};

int main() {
    printf("***************************************************************\n");
    printf( "\t\t\t\t\t**Corretor Ortográfico (v1.0)\t\t\t\t\t\t**\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");

    int op;

    while(1) {
        printf("\t\t\t\t\tInsira Opção:\t\t\t\t\t\t\n");
        printf("\t\t1 - Carregar Texto:\t\t\t\t\t\t\n");
        printf("\t\t2 - Carregar Dicionário:\t\t\t\t\t\t\n");
        printf("\t\t3 - Iniciar Correção:\t\t\t\t\t\t\n");
        printf("\t\t0 - Sair:\t\t\t\t\t\t\n");

        cout << ">>" ;
        cin >> op;

        try {
            switch (op) {
                case SAIR:
                    cout << "Bye!" << endl;
                break;
                case CARREGATEXTO:
                    printf("\t\tInsira Nome do arquivo de texto\t\t\t\n");
                    string nome_texto;
                    cout << ">>" ;
                    cin >> nome_texto;
                break;
                case CARREGADIC:
                    printf("\t\tInsira Nome do arquivo de Dicionario\t\t\t\n");
                    string nome_dic;
                    cout << ">>" ;
                    cin >> nome_dic;
                break;
                case CORRIGI:
                    Texto txt(nome_texto);
                    dicionario dic(nome_dic);
                    // Rest of code
                break;
            }
        } catch( std::exception &e ) {
            cout << "ERRO! " << e.what() << endl;
            continue;
        }
    }
    return 0;
}
