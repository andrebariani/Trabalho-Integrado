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
*/
class Arvore {
    typedef struct _node{
        T dado;
        bool bal[2];
        struct _node * esq;
        struct _node * dir;
    }Node;
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
        Node * raiz;

};


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
    Node* p = new Node;

    if(p){
        //Atribuir valor no no
        p->dados = d;
        p->esq=NULL;
        p->dir=NULL;

        //Arvore vazia
        if(raiz==NULL)
            raiz=p;

        else{
            Node * t = raiz;
            //Enquanto houverem nós
            Node * pai = NULL;
            while(t)
            {
                //Define o no como o novo pai
                pai=t;
                //Procure a posição correta
                if(d<t->dado)
                    t=t->dir;
                else if(d>t->dado)
                    t=t->esq;
            }
            //Posição encontrada, corrija o pai
            if(d<pai->dado)
                pai->dir=p;
            else if(d>pai->dado)
                pai->esq=p;
        }
    }
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
