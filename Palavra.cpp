/*! \file Palavra.cpp
    \brief Classe palavra e funções relacionadas
 *  Autor: Anderson Pinheiro Garrote

 *  Created on 17 de Maio de 2018, 11:14
*/
/*! \class Palavra
    \brief Classe de manipulação de palavras
*/

#include "Palavra.h"
#include <iostream>
#include <string>

Palavra::Palavra(std::string p){
    palavra=p;
}

bool Palavra::semelhantes( Palavra& p2)
{
    return palavra.at(0)==p2.getPalavra().at(0) && palavra.at(1)==p2.getPalavra().at(1);
}
bool Palavra::operator==( Palavra& p2)
{
    return palavra==p2.getPalavra();
}
bool Palavra::operator<( Palavra& p2)
{
    return palavra<p2.getPalavra();
}
void Palavra::operator=( Palavra p2)
{
    palavra = p2.getPalavra();
}
void Palavra::setPalavra(std::string p){
    palavra=p;
}
std::string Palavra::getPalavra(){
    return palavra;
}

std::ostream &operator<< (std::ostream & o, Palavra& p){
    o << p.getPalavra();
    return o;
}

std::istream &operator>> (std::istream & i, Palavra& p){
    std::string pal;
    i >> pal;
    p.setPalavra(pal);
    return i;
}
