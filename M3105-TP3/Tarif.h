/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tarif.h
 * Author: vangriea
 *
 * Created on March 18, 2020, 6:31 PM
 */

#ifndef TARIF_H
#define TARIF_H
#include "NombreContraint.h"
#include <string>
#include <iostream>

class Tarif {
public:
    Tarif(const std::string & unLibelle, float unPrixKilo);
    
    const std::string& getLibelle() const;
    
    void setLibelle(const std::string& libelle);
    
    float getPrixAuKm() const;
    
    void setPrixKilo(float prixKilo);
    
    void saisir(std::istream& entree = std::cin);
    
    void afficher(std::ostream& sortie = std::cout) const;
   
    
private:
    std::string libelle;
    NombreContraint<float> prixAuKm;
    static constexpr float PRIXMIN = 0.01;
    static constexpr float PRIXMAX = 10.0;
};

std::ostream& operator<< (std::ostream& sortie, const Tarif& t);

std::istream& operator>> (std::istream& entree, Tarif& t);

#endif /* TARIF_H */

