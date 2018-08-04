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
    /*    struct _no (T _data, int _bal=0){
            dado = _dado;
            esq = dir = NULL;
            bal = _bal;
        }
    */
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

        ///Em ordem
        /** Percorre a arvore em ordem, processando com a função recebida de parametro.*/
        void percursoEmOrdem( void (*processa)(T)/**< [in] Função que processa o No*/);

        ///Busca
        /** Retorna um ponteiro para T se o T foi encontrado, NULL do contrário.*/
        T * busca( T d /**< [in] Dado a ser buscado.*/);

    private:
        No * raiz;
        ///Remove No
        /**
         * Método auxiliar para remover o No
         * @param  p Ponteiro No atual
         * @param  d Dado a ser buscado
         * @return   Ponteiro da arvore sem o No
         */
        No * remove_no( No *p, T d );
        // No maximo
        /**
         * Método auxiliar para encontrar o maior valor de uma subarvore
         * @param  p raiz da subarvore
         * @return   Ponteiro pro maior No
         */
        No * max_node( No* p );
        ///Em Ordem
        /**
         * Método auxiliar para realizar o percurso em ordem, usando os Nos
         * @param t Raiz da subarvore
         */
        void emOrdem(No * t, void (*processa)(T));
        ///Rotação Esquerda
        /**
         * Método auxiliar para realizar a rotação
         * @param  A Ponteiro do nó atual
         * @return   No rotacionado
         */
        No* rotEE( No* A );
        ///Rotação Direita
        /**
         * Método auxiliar para realizar a rotação
         * @param  A Ponteiro do nó atual
         * @return   No rotacionado
         */
        No* rotDD( No* A );
        ///Rotação DireitaEsquerda
        /**
         * Método auxiliar para realizar a rotação
         * @param  A Ponteiro do nó atual
         * @return   No rotacionado
         */
        No* rotDE( No* A );
        ///Rotação EsquerdaDireita
        /**
         * Método auxiliar para realizar a rotação
         * @param  A Ponteiro do nó atual
         * @return   No rotacionado
         */
        No* rotED( No* A );
};


///Busca Semelhantes
/** Retorna verdadeiro se o T foi encontrado, falso do contrário.*/
//T * buscaSemelhantes( T d /**< [in] Dado a ser buscado.*/, Iterator it);


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
        p->dado = d;
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
            p->dado = d;
            p->esq=NULL;
            p->dir=NULL;
            //Corrija o pai
            pai->esq=p;
        }
        else if(d>pai->dado){
            //Aloca o No
            No* p = new No;
            //Atribuir valor no No
            p->dado = d;
            p->esq=NULL;
            p->dir=NULL;
            //Corrija o pai
            pai->dir=p;
        }
        else//Dado igual o pai
        {
            pai->dado=d;
        }
    }
    //Balanceia

}

///Remove
/** Remove o T d na arvore.
    Retorna exceção se não for removido com sucesso.*/
template <class T>
void Arvore<T>::remove( T d /**< [in] Dado a ser removido.*/)
{
    raiz=remove_no(raiz, d);
}

template <class T>
typename Arvore<T>::No* Arvore<T>::remove_no( No *p, T d ) {
    if( !p )
        return 0;
    if( d < p->dado )
        p->esq = remove_no(p->esq,d);
    else if( d > p->dado )
        p->dir = remove_no(p->dir,d);
    else {
        if( !p->dir ) {
            No *esquerda = p->esq;
            delete p;
        return esquerda;
        }
        if( !p->esq ) {
            No *direita = p->dir;
            delete p;
            return direita;
        }
        p->dado = max_node(p->esq)->dado;
        p->esq = remove_no( p->esq, p->dado);
    }
    return p;
}

///Busca
/** Retorna ponteiro para T se o T foi encontrado, NULL do contrário.*/
template <class T>
T * Arvore<T>::busca( T d /**< [in] Dado a ser buscado.*/)
{
    No * p=raiz;
    while( p )
    {
        if( d < p->dado )
            p = p->esq;
        else if( d > p->dado )
            p = p->dir;
        else // d == p->dado
            return  &p->dado;
    }
    return NULL;
}

//Método auxiliar para encontrar o maior valor de uma subarvore
template <class T>
typename Arvore<T>::No* Arvore<T>::max_node( No* p ) {
    if( ! p->dir )
        return p;
    else
        return max_node( p->dir );
}

//Método auxiliar para realizar a rotação EE
template <class T>
typename Arvore<T>::No* Arvore<T>::rotEE( No* A ) {
    No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    A->bal = 0;
    B->bal = 0;
    return B;
}

//Método auxiliar para realizar a rotação DD
template <class T>
typename Arvore<T>::No* Arvore<T>::rotDD( No* A ) {
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    A->bal = 0;
    B->bal = 0;
    return B;
}

//Método auxiliar para realizar a rotação DE
template <class T>
typename Arvore<T>::No* Arvore<T>::rotDE( No* A ) {
    No* B = A->dir;
    No* C = B->esq;
    B->esq = C->dir;
    C->dir = B;
    A->dir = C->esq;
    C->esq = A;
    //Corrgir balanceamento
    if( C->bal == -1 ) {
        A->bal = 0;
        B->bal = 1;
        C->bal = 0;
    } else if( C->bal == 1 ) {
        A->bal = -1;
        B->bal = 0;
        C->bal = 0;
    } else { // C->bal == 0
        A->bal = 0;
        B->bal = 0;
    }
    return C;
}

//Método auxiliar para realizar a rotação ED
template <class T>
typename Arvore<T>::No* Arvore<T>::rotED( No* A ) {
    No* B = A->esq;
    No* C = B->dir;
    B->dir = C->esq;
    C->esq = B;
    A->esq = C->dir;
    C->dir = A;
    //Corrgir balanceamento
    if( C->bal == -1 ) {
        A->bal = 1;
        B->bal = 0;
        C->bal = 0;
    } else if( C->bal == 1 ) {
        A->bal = 0;
        B->bal = -1;
        C->bal = 0;
    } else { // C->bal == 0
        A->bal = 0;
        B->bal = 0;
    }
    return C;
}

//Método auxiliar para realizar o percurso em ordem, usando os Nos
template <class T>
void Arvore<T>::emOrdem(No * t, void (*processa)(T)){
    if(t){
        emOrdem(t->esq, processa);
        processa(t->dado);
        emOrdem(t->dir, processa);
    }
}

///Em ordem
/** Percorre a arvore em ordem, processando com a função recebida de parametro.*/
template <class T>
void Arvore<T>::percursoEmOrdem( void (*processa)(T)/**< [in] Função que processa o No*/)
{
    emOrdem(raiz, processa);
}

#endif /* ARVORE_H */
