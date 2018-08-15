/*! \file Arvore.h
    \brief Classe Arvore Binaria de Busca
 *  \author Anderson Pinheiro Garrote
 *  \author Thiago Yussuki Uehara
 *  Created on 23 de Maio de 2018, 18:10
*/

#ifndef ARVORE_H
#define ARVORE_H

#include<queue>
#include<setack>
#include<deque>

template <class T>

/*! \class Arvore Binaria de Busca
    \brief Classe de manipulação de arvores de busca
    Implementação AVL
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

        ///Destrutor
        /* Destroi a arvore*/
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

        ///Pós ordem
        /** Percorre a arvore pós-ordem, processando com a função recebida de parametro.*/
        void percursoPosOrdem( void (*processa)(T)/**< [in] Função que processa o No*/);

        ///Busca
        /** Retorna um ponteiro para T se o T foi encontrado, NULL do contrário.*/
        T * busca( T d /**< [in] Dado a ser buscado.*/);

        ///Get Quantidade de Nos
        /** Retorna o numero de Nos da Arvore*/
        unsigned getQtd();

        ///Método para buscar um intervalo, e retornar um std::queue<T> com os elementos entre o maior e o menor
        void buscaIntervalo( std::queue<T> &q/**< [out] Fila com elementos do intervalo.*/,
                        T menor         /**< [in] Limitante inferior.*/,
                        T maior         /**< [in] Limitante superior.*/);
        ///Método para buscar um intervalo, e retornar um std::deque<T> com os elementos entre o maior e o menor
        void buscaIntervalo( std::deque<T> &d/**< [out] Fila com elementos do intervalo.*/,
                        T menor         /**< [in] Limitante inferior.*/,
                        T maior         /**< [in] Limitante superior.*/);

        ///Método para buscar um intervalo, e retornar um std::stack<T> com os elementos entre o maior e o menor
        void buscaIntervalo( std::stack<T> &s/**< [out] Fila com elementos do intervalo.*/,
                        T menor         /**< [in] Limitante inferior.*/,
                        T maior         /**< [in] Limitante superior.*/);

    private:
        No * raiz;
        unsigned qtd;
        ///Insere no
        /**
         * Método auxiliar para Inserir o dado d na arvore.
         * Retorna exceção se não for inserido com sucesso.
         * @param  p         Ponteiro do nó atual
         * @param  d         Dado a ser inserido
         * @param  cresceuAltura Flag para saber se o no foi alocado
         * @return           Arvore com dado inserido
         */
        No* insere_no( No *p, T d , bool &cresceuAltura);
        ///Remove No
        /**
         * Método auxiliar para remover o No
         * @param  p Ponteiro No atual
         * @param  d Dado a ser buscado
         * @return   Ponteiro da arvore sem o No
         */
        No * remove_no( No *p, T d , bool &diminuiuAltura);
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
        ///Pos Ordem
        /**
         * Método auxiliar para realizar o percurso em ordem, usando os Nos
         * @param t Raiz da subarvore
         */
        void posOrdem(No * t, void (*processa)(T));
        ///
        /**
         * Método auxiliar para buscar um intervalo, e retornar um std::stack<T> com os elementos entre o maior e o menor
         * @param  p     Ponteiro para no atual
         * @param  q     Fila para retornar elementos
         * @param  menor Limitante superior
         * @param  maior Limitante inferior
         */
        void  buscaIntervalo_no(No* p, std::queue<T> &q, T menor, T maior);

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

        ///Método auxiliar para realizar a rotação EE na remocao
        No* rotEEremove(No* p, bool &mudouAltura);

        ///Método auxiliar para realizar a rotação ED na remocao
        No* rotEDremove(No* p, bool &mudouAltura);

        ///Método auxiliar para realizar a rotação DD na remocao
        No* rotDDremove(No* p, bool &mudouAltura);

        ///Método auxiliar para realizar a rotação DE na remocao
        No* rotDEremove(No* p, bool &mudouAltura);
};


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

///Destrutor
/* Destroi a arvore*/
template <class T>
Arvore<T>::~Arvore() {
    while (!vazia())
        remove(raiz->dado);

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
    bool cresceuAltura=false;
    raiz=insere_no(raiz, d, cresceuAltura);
}
///Insere No
/** Funcao privada que insere o dado d na arvore.
    Retorna exceção se não for inserido com sucesso.*/
template <class T>
typename Arvore<T>::No* Arvore<T>::insere_no( No *p, T d , bool &cresceuAltura) {
    if( !p )//Posicao encontrada
    {
        //Alocar No
        p = new No;
        qtd++;

        //Atribuir dado no No
        p->dado = d;
        p->bal=0;
        p->esq=NULL;
        p->dir=NULL;
        //cresceuAltura
        cresceuAltura=true;
    }
    else{
        if( d < p->dado ){
            //Chama para  subarvore esquerda
            p->esq = insere_no(p->esq,d,cresceuAltura);
            //Corrige balanceamento
            if(cresceuAltura)
            {
                if(p->bal==-1)
                    if(p->esq->bal ==-1)//se foi inserido na subarvore esquerda do No esq
                        p=rotEE(p);
                    else                //se foi inserido na subarvore direita do No esq
                        p=rotED(p);
                else{
                    p->bal--;
                    if(p->bal==0)
                        cresceuAltura=false;
                }
            }
        }
        else if( d > p->dado ){
            //Chama para  subarvore direita
            p->dir = insere_no(p->dir,d,cresceuAltura);
            //Corrige balanceamento
            if(cresceuAltura)
            {
                if(p->bal==1){
                    if(p->dir->bal == 1)//se foi inserido na subarvore direita do No dir
                        p=rotDD(p);
                    else                //se foi inserido na subarvore esquerda do No dir
                        p=rotDE(p);
                }
                else{
                    p->bal++;
                    if(p->bal==0)
                        cresceuAltura=false;
                }
            }
        }
        else
        {
            //Atualiza o dado
            p->dado=d;
            //NAO mudou altura
            cresceuAltura=false;
        }
    }
    return p;
}

///Remove
/** Remove o T d na arvore.*/
template <class T>
void Arvore<T>::remove( T d /**< [in] Dado a ser removido.*/)
{
    bool diminuiuAltura = false;
    raiz=remove_no(raiz, d, diminuiuAltura);
}

template <class T>
typename Arvore<T>::No* Arvore<T>::remove_no( No *p, T d , bool &diminuiuAltura)
{
    if( !p )
        return NULL;
    if( d < p->dado ){
        p->esq = remove_no(p->esq,d,diminuiuAltura);
        //Verificar balanceamento
        if(diminuiuAltura)
        {
            if(p->bal==1){
                if(p->dir->bal == 1)//se foi inserido na subarvore direita do No dir
                    p=rotDDremove(p,diminuiuAltura);
                else                //se foi inserido na subarvore direita do No dir
                    p=rotDEremove(p,diminuiuAltura);
            }
            else{
                p->bal++;
                if(p->bal==1)
                    diminuiuAltura=false;
            }
        }
    }
    else if( d > p->dado ){
        p->dir = remove_no(p->dir,d,diminuiuAltura);
        //Verificar balanceamento
        if(diminuiuAltura)
        {
            if(p->bal==-1)
                if(p->esq->bal ==-1)
                    p=rotEEremove(p,diminuiuAltura);
                else
                    p=rotEDremove(p,diminuiuAltura);
            else{
                p->bal--;
                if(p->bal==-1)
                    diminuiuAltura=false;
            }
        }

    }
    else {
        //Dado encontrado
        if( !p->dir ) {
            No *esquerda = p->esq;
            delete p;
            qtd--;
            diminuiuAltura=true;
            return esquerda;
        }
        if( !p->esq ) {
            No *direita = p->dir;
            delete p;
            qtd--;
            diminuiuAltura=true;
            return direita;
        }
        p->dado = max_node(p->esq)->dado;
        p->esq = remove_no( p->esq, p->dado, diminuiuAltura);
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

///Método auxiliar para encontrar o maior valor de uma subarvore
template <class T>
typename Arvore<T>::No* Arvore<T>::max_node( No* p ) {
    if( ! p->dir )
        return p;
    else
        return max_node( p->dir );
}

///Método auxiliar para realizar a rotação EE
template <class T>
typename Arvore<T>::No* Arvore<T>::rotEE( No* A ) {
    No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    A->bal = 0;
    B->bal = 0;
    return B;
}

///Método auxiliar para realizar a rotação DD
template <class T>
typename Arvore<T>::No* Arvore<T>::rotDD( No* A ) {
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    A->bal = 0;
    B->bal = 0;
    return B;
}

///Método auxiliar para realizar a rotação DE
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

///Método auxiliar para realizar a rotação ED
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

///Método auxiliar para realizar a rotação EE na remocao
template <class T>
typename Arvore<T>::No* Arvore<T>::rotEEremove(No* p, bool &mudouAltura) {
    No* A = p->esq;
    p->esq = A->dir;
    A->dir= p;
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

///Método auxiliar para realizar a rotação ED na remocao
template <class T>
typename Arvore<T>::No* Arvore<T>::rotEDremove(No* p, bool &mudouAltura) {
    mudouAltura = true;
    return rotED(p);
}

///Método auxiliar para realizar a rotação DD na remocao
template <class T>
typename Arvore<T>::No* Arvore<T>::rotDDremove(No* p, bool &mudouAltura) {
    No *B = p->dir;
    p->dir = B->esq;
    B->esq = p;
    if(B->bal == 0) {
        B->bal = -1;
        p->bal = 1;
        mudouAltura = false;
    } else {
        B->bal = 0;
        p->bal = 0;
        mudouAltura = true;
    }
    return B;
}

///Método auxiliar para realizar a rotação DE na remocao
template <class T>
typename Arvore<T>::No* Arvore<T>::rotDEremove(No* p, bool &mudouAltura) {
    mudouAltura = true;
    return rotDE(p);
}

///Método auxiliar para realizar o percurso em posOrdem, usando os Nos
template <class T>
void Arvore<T>::posOrdem(No * t, void (*processa)(T)){
    if(t){
        posOrdem(t->esq, processa);
        posOrdem(t->dir, processa);
        processa(t->dado);
    }

}

///Em ordem
/** Percorre a arvore pós-ordem, processando com a função recebida de parametro.*/
template <class T>
void Arvore<T>::percursoPosOrdem( void (*processa)(T)/**< [in] Função que processa o No*/)
{
    posOrdem(raiz, processa);
}

///Get Quantidade de Nos
/** Retorna o numero de Nos da Arvore*/
template <class T>
unsigned Arvore<T>::getQtd() {
    return qtd;
}

///Método para buscar um intervalo, e retornar um std::queue<T> com os elementos entre o maior e o menor
template <class T>
void Arvore<T>::buscaIntervalo(std::queue<T> &q, T menor, T maior) {
    //Esvazia Fila
    while(!q.empty())
        q.pop();
    //Chama funcao privada
    buscaIntervalo_no(raiz, q, menor, maior);
}

///Método auxiliar para buscar um intervalo, e retornar um std::queue<T> com os elementos entre o maior e o menor
template <class T>
void  Arvore<T>::buscaIntervalo_no(No* p, std::queue<T> &q, T menor, T maior) {
    if (!p)
        return;
    if( menor < p->dado )
        buscaIntervalo_no( p->esq, q, menor, maior);
    if( menor<= p->dado && maior >= p->dado ){
        q.push(p->dado);
    }
    if( maior > p->dado )
        buscaIntervalo_no( p->dir, q, menor, maior);
}

///Método para buscar um intervalo, e retornar um std::deque<T> com os elementos entre o maior e o menor
template <class T>
void Arvore<T>::buscaIntervalo(std::deque<T> &d, T menor, T maior) {
    //Esvazia Deque
    while(!d.empty())
        d.pop_front();
    //Chama funcao privada
    buscaIntervalo_no(raiz, d, menor, maior);
}

///Método auxiliar para buscar um intervalo, e retornar um std::deque<T> com os elementos entre o maior e o menor
template <class T>
void  Arvore<T>::buscaIntervalo_no(No* p, std::deque<T> &d, T menor, T maior) {
    if (!p)
        return;
    if( menor < p->dado )
        buscaIntervalo_no( p->esq, d, menor, maior);
    if( menor<= p->dado && maior >= p->dado ){
        d.push_front(p->dado);
    }
    if( maior > p->dado )
        buscaIntervalo_no( p->dir, d, menor, maior);
}
///Método para buscar um intervalo, e retornar um std::stack<T> com os elementos entre o maior e o menor
template <class T>
void Arvore<T>::buscaIntervalo(std::stack<T> &s, T menor, T maior) {
    //Esvazia Pilha
    while(!q.empty())
        s.pop();
    //Chama funcao privada
    buscaIntervalo_no(raiz, s, menor, maior);
}

///Método auxiliar para buscar um intervalo, e retornar um std::stack<T> com os elementos entre o maior e o menor
template <class T>
void  Arvore<T>::buscaIntervalo_no(No* p, std::stack<T> &s, T menor, T maior) {
    if (!p)
        return;
    if( menor < p->dado )
        buscaIntervalo_no( p->esq, s, menor, maior);
    if( menor<= p->dado && maior >= p->dado ){
        s.push(p->dado);
    }
    if( maior > p->dado )
        buscaIntervalo_no( p->dir, s, menor, maior);
}



#endif /* ARVORE_H */
