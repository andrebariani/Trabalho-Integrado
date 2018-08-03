#include "Texto.h"
#include "Palavra.h"
using namespace std;

Texto::Texto( string na ) {
    total_size = 0;
    word_first_flag = false;
    nomearq = na;
    string p = "";
    string d = "";
    vector<string>::iterator it_delim;

    it_palavras = palavras.begin();
    it_delim = delim.begin();

    // Tratando da Extensão do arquivo de entrada
    size_t found = nomearq.find(".txt");

    if(found == std::string::npos) {
        cout << ".txt not found" << endl;
        nomearq = nomearq + ".txt";
    }
    //

    cout << nomearq << endl;
    ifstream arq(nomearq);

    char c;

    while(arq.get(c)) {
        if(total_size > 10000) // Atingiu o tamanho máximo do vetor
            break;

        switch (isalpha(c)) {
            case 0: // Se não
                cout << "Delim Found: " <<  "-" << c << "-" << endl;

                if(p == "") {
                    d = d + c;
                    cout << "-" << d << "-"<< endl;
                }
                else {
                    Palavra paux;
                    paux = p;
                    palavras.push_back(paux);
                    // *(it_palavras++) = paux;
                    cout << paux << " Inserted!" << endl << endl;
                    p = "";
                    d = d + c;
                }
            break;
            default: // Se o caracter for Letra
                cout << "Letter Found: " << c << endl;

                // Salvando qual entre os dois aparecem primeiro no arquivo
                if(total_size == 0) word_first_flag = true;

                if(d == "") {
                    p = p + c;
                    cout << p << endl;
                }
                else {
                    delim.push_back(d);
                    cout << "-" << d << "-" << " Inserted!" << endl << endl;
                    d = "";
                    p = p + c;
                }
            break;
        }

        ++total_size;
    }

    // cout << "boy" ;

    // Por causa do salvarArquivo(), esse trecho é necessário para pegar a última pontuação
    // Não é necessário para o vetor palavras pois todo arquivo .txt termina com '\n'
    if(d != "")
        delim.push_back(d);

    it_palavras = palavras.begin();

    // cout << total_size << endl;
    arq.close();
}

Palavra Texto::percorrerTexto() {
    if( it_palavras + 1 > palavras.end() ) {
        Palavra Null;
        return Null;
    }
    return *it_palavras++;
}

Palavra Texto::getPalavraAnterior() {
    if( (it_palavras - 1) == palavras.begin() ) {
        Palavra Null;
        return Null;
    }
    return *(it_palavras - 2);
}

Palavra Texto::getPalavraProximo() {
    if( it_palavras == palavras.end() ) {
        Palavra Null;
        return Null;
    }
    return *(it_palavras);
}

void Texto::corrigirPalavra( Palavra corrigida ) {
    *(it_palavras - 1) = corrigida;
}

void Texto:: salvarArquivo() {
    // size_t found = nomearq.find(".txt");
    // nomearq.insert(found, "-Copy");

    string n = "Copy-" + nomearq;
    ofstream arq( n );

    it_palavras = palavras.begin();
    vector<string>::iterator it_delim = delim.begin();

    int i = 0;
    if(word_first_flag) {
        while( i++ < total_size ) {
            if((it_palavras) < palavras.end())
                arq << *(it_palavras++);
            if((it_delim) < delim.end())
                arq << *(it_delim++);
        }
    } else {
        while( i++ < total_size ) {
            if((it_delim) < delim.end())
                arq << *(it_delim++);
            if((it_palavras) < palavras.end())
                arq << *(it_palavras++);
        }
    }

    cout << "Arquivo Salvo" << endl;
}
