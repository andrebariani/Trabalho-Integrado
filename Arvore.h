/*! \file Arvore.h
    \brief Classe Arvore Binaria de Busca
 *  Autor: Anderson Pinheiro Garrote
 *  Created on 23 de Maio de 2018, 18:10
*/


#ifndef ARVORE_H
#define ARVORE_H

#include<iostream>
#include <vector>

template <class T>

/*! \class Node
    \brief Classe de nós para a Arvore Binaria de Busca
*/
class Node {
    public:
        ///Construtor
        /** Inicializa o No*/
        Node(T dado);

        ///Get Dado
        /** Retorna o dado do tipo T armazenado no node*/
        T getDado();
        ///Set Dado
        /** Armazena no node o dado do tipo T */
        void setDado( T dado);

        ///Get No Direito
        /** Retorna o ponteiro do filho direito do node*/
        Node * getDir();
        ///Set No Direito
        /** Define o node apontado por p como o filho direito do node*/
        void setDir( Node * p);

        ///Get No Esquerdo
        /** Retorna o ponteiro do filho esquerdo do node*/
        Node * getEsq();
        ///Set No Esquerdo
        /** Define o node apontado por p como o filho esquerdo do node*/
        void setEsq( Node * p);

    private:
        T dado;         ///< Dado do tipo T
        Node * dir, esq;///< Ponteiros direito e esquerdo
        bool bal[2];    ///< Fator de balanceamento
}

/*! \class Arvore Binaria de Busca
    \brief Classe de manipulação de arvores de busca
*/
class Arvore {
    public:

        ///Construtor
        /** Inicializa a Arvore*/
        Arvore();

        Arvore(const Arvore& orig);

        virtual ~Arvore();

        ///Vazia
        /** Retorna verdadeiro se a Arvore está vazia, falso do contrário.*/
        bool vazia();

        ///Insere
        /** Insere o T d na arvore.
            Retorna exceção se não for inserido com sucesso.*/
        void insere( T d /**< [in] Dado a ser inserido.*/);

        ///Remove
        /** Remove o T d na arvore.
            Retorna exceção se não for inserido com sucesso.*/
        void remove( T d /**< [in] Dado a ser removido.*/);

        ///Busca
        /** Retorna verdadeiro se o T foi encontrado, falso do contrário.*/
        T * busca( T d /**< [in] Dado a ser buscado.*/);

    private:
        unsigned qtd;
        /*std::vector*/ T dados[1000];

};


/******************************************************************************
* IMPLEMENTAÇÃO
*******************************************************************************/

template <class T>
Arvore<T>::Arvore() {
    qtd=0;
}
template <class T>
Arvore<T>::Arvore(const Arvore& orig) {
}
template <class T>
Arvore<T>::~Arvore() {
}

///Vazia
/** Retorna verdadeiro se a Arvore está vazia, falso do contrário.*/
template <class T>
bool Arvore<T>::vazia()
{
    return qtd == 0;
}

///Insere
/** Insere o dado d na arvore.
    Retorna exceção se não for inserido com sucesso.*/
template <class T>
void Arvore<T>::insere( T d /**< [in] Dado a ser inserido.*/)
{
    dados[qtd]=d;
    qtd++;
}

///Remove
/** Remove o T d na arvore.
    Retorna exceção se não for removido com sucesso.*/
template <class T>
void Arvore<T>::remove( T d /**< [in] Dado a ser removido.*/)
{
    for(int i=0;i<qtd;i++)
        if(d==dados[i])
        {
            qtd--;
            for(i; i<qtd; i++)
                dados[i]=dados[i+1];
            return;
        }
    //dados.erase(dados.begin);
}

///Busca
/** Retorna verdadeiro se o T foi encontrado, falso do contrário.*/
template <class T>
T * Arvore<T>::busca( T d /**< [in] Dado a ser buscado.*/)
{
    for(int i=0;i<qtd;i++)
        if(d==dados[i])
            return &dados[i];

    return NULL;
}


#endif /* ARVORE_H */
