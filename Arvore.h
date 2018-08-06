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

        ///Get Quantidade de Nos
        /** Retorna o numero de Nos da Arvore*/
        unsigned getQtd();

    private:
        No * raiz;
        unsigned qtd;
        No* insere_no( No *p, T d , bool &noAlocado);
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
    qtd=0;
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
    while (!vazia()) {
        remove(raiz->dado);
    }
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
    bool noAlocado=false;
    raiz=insere_no(raiz, d, noAlocado);
    if(noAlocado)
        qtd++;
}
///Insere No
/** Funcao privada que insere o dado d na arvore.
    Retorna exceção se não for inserido com sucesso.*/
template <class T>
typename Arvore<T>::No* Arvore<T>::insere_no( No *p, T d , bool &noAlocado) {
    if( !p )//Posicao encontrada
    {
        //Alocar No
        p = new No;
        //Atribuir dado no No
        p->dado = d;
        p->bal=0;
        p->esq=NULL;
        p->dir=NULL;
        //noAlocado
        noAlocado=true;
    }
    else{
        if( d < p->dado ){
            //Chama para  subarvore esquerda
            p->esq = insere_no(p->esq,d,noAlocado);
            //Corrige balanceamento
            if(noAlocado && p->bal==-1)
                if(p->esq->bal == -1)//se foi inserido na subarvore esquerda do No esq
                    p=rotEE(p);
                else//se foi inserido na subarvore direita do No esq
                    p=rotED(p);
            else
                p->bal--;
        }
        else if( d > p->dado ){
            //Chama para  subarvore direita
            p->dir = insere_no(p->dir,d,noAlocado);
            //Corrige balanceamento
            if(noAlocado && p->bal==1)
                if(p->dir->bal == 1)//se foi inserido na subarvore direita do No dir
                    p=rotDD(p);
                else//se foi inserido na subarvore direita do No dir
                    p=rotDE(p);
            else
                p->bal++;
        }
        else
        {
            //Atualiza o dado
            p->dado=d;
            //NAO mudou altura
            noAlocado=false;
        }
    }
    return p;
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
        return NULL;
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
/*
No* rotEEremove(No* p, int &mudouAltura) {
    No* A = p->esquerda;
    p->esquerda = A->direita;
    A->direita = p;
    if(A->bal == 0) {
        A->bal = 1;
        p->bal = -1;
        mudouAltura = 0;
    } else {
        A->bal = 0;
        p->bal = 0;
        mudouAltura = 1;
    }
    return A;
}
No* rotEDremove(No* n, int &mudouAltura) {
    mudouAltura = 1;
    return rotED(p);
}

No* rotDDremove(No* p, int &mudouAltura) {
    No *B = p->direita;
    p->direita = B->esquerda;
    B->esquerda = p;
    if(B->bal == 0) {
        B->bal = -1;
        p->bal = 1;
        mudouAltura = 0;
    } else {
        B->bal = 0;
        p->bal = 0;
        mudouAltura = 1;
    }
    return B;
}
No* rotDEremove(No* p, int &mudouAltura) {
    mudouAltura = 0;
    return rotDE(p);
}
*/
//Método auxiliar para realizar o percurso em ordem, usando os Nos
template <class T>
void Arvore<T>::emOrdem(No * t, void (*processa)(T)){
    if(t){
        emOrdem(t->esq, processa);
        processa(t->dado);
        std::cout << "(bal=["<< t->bal << "])" << '|';
        emOrdem(t->dir, processa);
    }

}

///Em ordem
/** Percorre a arvore em ordem, processando com a função recebida de parametro.*/
template <class T>
void Arvore<T>::percursoEmOrdem( void (*processa)(T)/**< [in] Função que processa o No*/)
{
    emOrdem(raiz, processa);
    std::cout  << '\n';
}

///Get Quantidade de Nos
/** Retorna o numero de Nos da Arvore*/
template <class T>
unsigned Arvore<T>::getQtd(){
    return qtd;
}


#endif /* ARVORE_H */
