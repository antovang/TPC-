/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conteneur.h
 * Author: vangriea
 *
 * Created on March 20, 2020, 10:36 PM
 */

#ifndef CONTENEUR_H
#define CONTENEUR_H
#include <vector>
#include <iostream>
#include "NombreContraint.h"

template <class T>
class Conteneur {
public:
    Conteneur();
    
    ~Conteneur();
    
    void ajouter(const T& element);
    
    void afficher(std::ostream & sortie = std::cout) const;
    
    const T& choisirElement(std::ostream& sortie = std::cout, std::istream& entree = std::cin);
    
private:
    std::vector<const T*> m_contenu;
};

template<class T>
std::ostream& operator<< (std::ostream& sortie, const Conteneur<T>& c);


#include "Conteneur.cpp"
#endif /* CONTENEUR_H */

