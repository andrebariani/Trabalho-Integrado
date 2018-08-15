/*! \file Texto.h
    \brief Classe texto e funções relacionadas
 *  \author André Matheus Bariani Trava
 *  Created on 30 de Maio de 2018, 14:35
*/
/*! \class Texto
    \brief Classe de manipulação de um texto
*/

#include "Texto.h"
#include "Palavra.h"
using namespace std;

Texto::Texto( string na ) {
    total_size = 0;
    word_first_flag = false;
    nomearq = na;
    vector<wstring>::iterator it_delim;
    it_palavras = palavras.begin();
    it_delim = delim.begin();

    if(na != "")
        carregarNovoTexto(nomearq);
}

void Texto::carregarNovoTexto( string na ) {
    nomearq = na;
    wstring p = L"";
    wstring d = L"";

    setlocale(LC_ALL,"pt_BR.UTF-8");

    // Tratando da Extensão do arquivo de entrada
    size_t found = nomearq.find(".txt");

    if(found == std::string::npos)
        nomearq += ".txt";

    wifstream arq;

    arq.open(nomearq);

    if (!arq)
        throw std::runtime_error("Arquivo não encontrado\n");

    wchar_t c;

    while(arq.get(c)) {
        if(total_size > 10000) // Atingiu o tamanho máximo do vetor
            throw std::runtime_error("Texto com mais de 10000 palavras\n");

        switch (iswalpha(c)) {
            case 0: // Se não for letra

                if(p == L"") {
                    d = d + c;
                } else {
                    ++total_size;
                    Palavra paux;
                    paux = p;
                    palavras.push_back(paux);
                    p = L"";
                    d = d + c;
                }
            break;
            default: // Se for Letra
                // Salvando qual entre os dois aparecem primeiro no arquivo
                if(total_size == 0) word_first_flag = true;

                if(d == L"") {
                    p = p + c;
                } else {
                    delim.push_back(d);
                    d = L"";
                    p = p + c;
                }
            break;
        }

    }

    // Por causa do salvarArquivo(), esse trecho é necessário para pegar a última pontuação
    // Não é necessário para o vetor palavras pois todo arquivo .txt termina com '\n'
    if(d != L"")
        delim.push_back(d);

    it_palavras = palavras.begin();

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
    size_t found = nomearq.find(".txt");
    nomearq.insert(found, "-Corrigido");

    wofstream arq( nomearq );

    it_palavras = palavras.begin();
    vector<wstring>::iterator it_delim = delim.begin();

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

    palavras.erase(palavras.begin(), palavras.end());
    delim.erase(delim.begin(), delim.end());

    cout << "Arquivo "<< nomearq << " Salvo!" << endl;
}
