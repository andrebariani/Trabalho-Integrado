/*! \file Arvore.h
    \brief Classe Arvore e funções relacionadas
 *  Autor: Anderson Pinheiro Garrote
 *  Created on 23 de Maio de 2018, 18:10
*/
/*! \class Arvore
    \brief Classe de manipulação de arvores de busca
*/

#ifndef ARVORE_H
#define ARVORE_H

#include<iostream>
#include <vector>

template <class dado> 

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
        /** Insere o dado d na arvore.
            Retorna exceção se não for inserido com sucesso.*/ 
        void insere( dado d /**< [in] Dado a ser inserido.*/);
        
        ///Remove
        /** Remove o dado d na arvore.
            Retorna exceção se não for inserido com sucesso.*/ 
        void remove( dado d /**< [in] Dado a ser removido.*/);
        
        ///Busca
        /** Retorna verdadeiro se o dado foi encontrado, falso do contrário.*/ 
        dado * busca( dado d /**< [in] Dado a ser buscado.*/);

    private:
        unsigned qtd;
        /*std::vector*/ dado dados[1000];

};


/******************************************************************************
* IMPLEMENTAÇÃO
*******************************************************************************/

template <class dado> 
Arvore<dado>::Arvore() {
    qtd=0;
}
template <class dado> 
Arvore<dado>::Arvore(const Arvore& orig) {
}
template <class dado> 
Arvore<dado>::~Arvore() {
}
 
///Vazia
/** Retorna verdadeiro se a Arvore está vazia, falso do contrário.*/ 
template <class dado> 
bool Arvore<dado>::vazia()
{
    return qtd == 0;
}

///Insere
/** Insere o dado d na arvore.
    Retorna exceção se não for inserido com sucesso.*/ 
template <class dado> 
void Arvore<dado>::insere( dado d /**< [in] Dado a ser inserido.*/)
{
    dados[qtd]=d;
    qtd++;
}

///Remove
/** Remove o dado d na arvore.
    Retorna exceção se não for removido com sucesso.*/ 
template <class dado> 
void Arvore<dado>::remove( dado d /**< [in] Dado a ser removido.*/)
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
/** Retorna verdadeiro se o dado foi encontrado, falso do contrário.*/ 
template <class dado> 
dado * Arvore<dado>::busca( dado d /**< [in] Dado a ser buscado.*/)
{
    for(int i=0;i<qtd;i++)
        if(d==dados[i])
            return &dados[i];
    
    return NULL;
}


#endif /* ARVORE_H */

