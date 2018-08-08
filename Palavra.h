/*! \file Palavra.h
    \brief Classe palavra e funções relacionadas
 *  Autor: Anderson Pinheiro Garrote
 *  Created on 17 de Maio de 2018, 11:14
*/
/*! \class Palavra
    \brief Classe de manipulação de palavras
*/

#ifndef PALAVRA_H
#define PALAVRA_H

#include<string>

class Palavra {
public:
    /// Construtor de Palavra

    /** Recebe uma string para inicializar a palavra */
    Palavra(std::wstring p=L""/**< [in] Palavra a ser inicializada. Por padrão, "". */);

    /// Comparacao palavras semelhantes
    /** \return Verdadeiro se as primeiras letras da palavra são iguais às respectivas de p2, falso do contrário.
     *  Dispara um erro caso as letras não existam. */
    bool semelhantes( Palavra& p2);

    /// Operador ==
    /** \return Verdadeiro se as palavras são iguais, falso do contrário.*/
    bool operator==( Palavra& p2);

    /// Operador <
    /** \return Verdadeiro se a palavra é menor que a segunda (valor de char menor e tamanho menor), falso do contrário.*/
    bool operator<( Palavra& p2);

    /// Operador <=
    /** \return Verdadeiro se a palavra é menor ou igual que a segunda (valor de char menor e tamanho menor), falso do contrário.*/
    bool operator<=( Palavra& p2);

    /// Operador >
    /** \return Verdadeiro se a palavra é maior que a segunda (valor de char menor e tamanho menor), falso do contrário.*/
    bool operator>( Palavra& p2);

    /// Operador >=
    /** \return Verdadeiro se a palavra é maior ou igual que a segunda (valor de char menor e tamanho menor), falso do contrário.*/
    bool operator>=( Palavra& p2);

    /// Operador =
    /** \Atribui o valor da palavra em uma segunda palavra.*/
    Palavra & operator=(const Palavra & p2 );
    // void operator=( Palavra p2/**< [in] Valor da Palavra para atribuir à segunda palavra*/ );

    /// set Palavra
    /** Atribui na palavra a string p.*/
    void setPalavra(std::wstring p /**< [in] Palavra a ser atualizada.*/);

    /// get Palavra
    /** \retorna string com a palavra armazenada.*/
    std::wstring getPalavra();

    /// minuscula
    /** \retorna string com a palavra armazenada e todos os caracteres minúsculos.*/
    Palavra minuscula();

private:
    std::wstring palavra; ///< String com a palavra armazenada

};

/// Operador <<
/** Exibe na tela a palavra p.
 * \return Objeto o (com a palavra p já exibida).*/
std::wostream &operator<< (std::wostream & o, Palavra &p /**< [in] Palavra a ser exibida.*/);

/// Operador >>
/** Escreve na palavra p.

 * \return Objeto i (com a palavra p já escrita).*/
std::wistream &operator>> (std::wistream & i, Palavra &p /**< [in] Palavra a ser escrita.*/);

#endif /* PALAVRA_H */
