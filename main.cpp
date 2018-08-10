#include <locale>
#include <string>
#include <iostream>

#include "Corretor.h"

enum {SAIR, CORRIGIR, CARREGATEXTO};

int main() {

    // $ g++ -o main_exe main.cpp Texto.cpp Palavra.cpp dicionario.cpp Corretor.cpp

    string nome_texto = "texto.txt";

    std::cout << "\n\t" << "**Corretor Ortográfico (v1.5)**" << "\t\t\t\n\n";

    int op;

    while(1) {
        std::cout << "Arquivo atual: " << nome_texto <<'\n';
        std::cout << "\tInsira Opção:\n";
        std::cout << "1 - Iniciar Correção\n";
        std::cout << "2 - Alterar Texto\n";
        std::cout << "0 - Sair:\n";

        cout << ">>" ;
        cin >> op;

        try {
            switch (op) {
                case SAIR:
                    cout << "Bye!" << endl;
                    return 0;
                break;
                case CARREGATEXTO: {
                    std::cout << "\tInsira Nome do arquivo de texto\t\t\t\n";
                    cout << ">>" ;
                    cin >> nome_texto;
                }
                break;
                case CORRIGIR: {
                    std::cout << "\tIniciando Correção...\t\t\t\n";

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
