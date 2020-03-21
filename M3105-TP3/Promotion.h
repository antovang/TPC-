/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promotion.h
 * Author: vangriea
 *
 * Created on March 18, 2020, 9:14 PM
 */

#ifndef PROMOTION_H
#define PROMOTION_H
#include <string>
#include <iostream>
#include "NombreContraint.h"

class Promotion {
public:
    Promotion(const std::string& unLibelle, float unTaux);
    
    const std::string& getLibelle() const;
    
    float getTauxReduction() const;
    
    void setLibelle(const std::string& libelle);
    
    void setTaux(float taux);
    
    float calculPrixReduit(float prix) const;
    
    void saisir(std::istream& entree = std::cin);
    
    void afficher(std::ostream& sortie = std::cout) const;

private:
    std::string libelle;
    NombreContraint<float> tauxReduction;
    static constexpr float TAUXMIN = 0.01;
    static constexpr float TAUXMAX = 0.99;
};

std::ostream& operator<< (std::ostream& sortie, const Promotion& p);

#endif /* PROMOTION_H */

