/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NombreContraint.cpp
 * Author: vangriea
 * 
 * Created on March 18, 2020, 6:06 PM
 */

#ifdef NOMBRECONTRAINT_H

using namespace std;

template <class T>
NombreContraint<T>::NombreContraint(T valeur, T min, T max):
        m_val(valeur),m_min(min),m_max(max){}

template <class T>
T NombreContraint<T>::getMin() const {
    return this->m_min;
}

template <class T>
T NombreContraint<T>::getMax() const {
    return this->m_max;
}

template <class T>
T NombreContraint<T>::getVal() const {
    return this->m_val;
}

template <class T>
NombreContraint<T>::operator T(){
    return getVal();
}

template <class T>
void NombreContraint<T>::setVal(T val) {
    try {
        if(val >= getMin() && val <= getMax()){
            this->m_val = val;
        }else{
            if(val < getMin())
                throw "val < min";
            
        throw "val > max";
        }
    }
    catch (char const * erreur) {
        cout << "Exception levée : " << erreur << endl ;
    }  
}

template <class T>
void NombreContraint<T>::saisir(istream & entree) {
    int val;
    entree >> val;
    this->setVal(val);
}

#endif

