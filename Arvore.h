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

/*! \class Arvore Binaria de Busca
    \brief Classe de manipulação de arvores de busca
    Implementação Rubro-Negra
*/
class Arvore {

    typedef struct _no{
        struct _no (T _data, int _bal=0){
            dado = _dado;
            esq = dir = NULL;
            bal = _bal;
        }

        T dado;
        int bal;
        struct _no * esq;
        struct _no * dir;
    }No;

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
        /** Retorna um ponteiro para T se o T foi encontrado, NULL do contrário.*/
        T * busca( T d /**< [in] Dado a ser buscado.*/);

    private:
        No * raiz;

};

///Busca Semelhantes
/** Retorna verdadeiro se o T foi encontrado, falso do contrário.*/
T * buscaSemelhantes( T d /**< [in] Dado a ser buscado.*/, Iterator it);


/******************************************************************************
* IMPLEMENTAÇÃO
*******************************************************************************/
///Construtor
/** Construtor da arvore, inicializa com ela vazia*/
template <class T>
Arvore<T>::Arvore() {
    raiz=NULL;
}
///Construtor por Cópia
/* Aloca uma nova arvore igual a original*/
template <class T>
Arvore<T>::Arvore(const Arvore& orig  /**< [in] Arvore de origem a ser copiada.*/) {
}

///Destrutor
/* Destroi a arvore*/
template <class T>
Arvore<T>::~Arvore() {
}

///Vazia
/** Retorna verdadeiro se a Arvore está vazia, falso do contrário.*/
template <class T>
bool Arvore<T>::vazia()
{
    return raiz==NULL;
}

///Insere
/** Insere o dado d na arvore.
    Retorna exceção se não for inserido com sucesso.*/
template <class T>
void Arvore<T>::insere( T d /**< [in] Dado a ser inserido.*/)
{
    //Arvore vazia
    if(raiz==NULL){
        //Aloca o No
        No* p = new No;
        raiz=p;
        //Atribuir valor no No
        p->dados = d;
        p->esq=NULL;
        p->dir=NULL;
    }
    else{
        No * t = raiz;
        No * pai = NULL;
        //Enquanto houverem nós
        while(t)
        {
            //Define o no como o novo pai
            pai=t;
            //Procure a posição correta
            if(d<t->dado)//dado menor
                t=t->esq;
            else if(d>t->dado)//dado maior
                t=t->dir;
            else//dado encontrado
                t=NULL;
        }

        //Posição encontrada
        if(d<pai->dado){//Dado menor que o pai
            //Aloca o No
            No* p = new No;
            //Atribuir valor no No
            p->dados = d;
            p->esq=NULL;
            p->dir=NULL;
            //Corrija o pai
            pai->esq=p;
        }
        else if(d>pai->dado){
            //Aloca o No
            No* p = new No;
            //Atribuir valor no No
            p->dados = d;
            p->esq=NULL;
            p->dir=NULL;
            //Corrija o pai
            pai->dir=p;
        }
        else//Dado igual o pai
        {
            pai->dados=d;
        }

    //Balaceia

}

///Remove
/** Remove o T d na arvore.
    Retorna exceção se não for removido com sucesso.*/
template <class T>
void Arvore<T>::remove( T d /**< [in] Dado a ser removido.*/)
{

}

///Busca
/** Retorna ponteiro para T se o T foi encontrado, NULL do contrário.*/
template <class T>
T * Arvore<T>::busca( T d /**< [in] Dado a ser buscado.*/)
{

}

No* rotEE( No* A ) {
    No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    return B;
}
No* rotDD( No* A ) {
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    return B;
}


#endif /* ARVORE_H */
