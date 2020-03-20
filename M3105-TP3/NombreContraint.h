/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NombreContraint.h
 * Author: vangriea
 *
 * Created on March 18, 2020, 6:06 PM
 */

#ifndef NOMBRECONTRAINT_H
#define NOMBRECONTRAINT_H
#include <iostream>

template <class T>
class NombreContraint {
public:
    NombreContraint(T valeur = 0, T min = 0, T max = 100);
    
    T getMin() const;
    
    T getMax() const;
    
    T getVal() const;
    
    operator T();
    
    void setVal(T val);
    
    void saisir(std::istream & entree = std::cin);
    
    void afficher(std::ostream & sortie = std::cout) const;
    
private:
    T m_min;
    T m_max;
    T m_val;
};

template <class T>
std::ostream& operator<< (std::ostream& sortie, const NombreContraint<T>& n){
    n.afficher();
    return sortie;
}

template <class T>
std::istream& operator>> (std::istream& entree, NombreContraint<T>& n){
    n.saisir();
    return entree;
}

#include "NombreContraint.cpp"
#endif /* NOMBRECONTRAINT_H */
