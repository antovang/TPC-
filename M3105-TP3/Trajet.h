/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trajet.h
 * Author: vangriea
 *
 * Created on March 18, 2020, 7:39 PM
 */

#ifndef TRAJET_H
#define TRAJET_H
#include <string>
#include <iostream>
#include "NombreContraint.h"

class Trajet {
public:
    Trajet(const std::string& villeDep,const std::string& villeArr,int dist);
    
    const string& getVilleDep() const;
    
    void setVilleDepart(const std::string& villeDep);
    
    const std::string& getVilleArrivee() const;
    
    void setVilleArrivee(const std::string& villeArr);
    
    int getDistance() const;
    
    void setDistance(float dist);
    
    void saisir(std::istream& entree = std::cin);
    
    void afficher(std::ostream& sortie = std::cout) const;

private:
    std::string villeDepart;
    std::string villeArrivee;
    NombreContraint<int> distance;
    static const unsigned int DISTANCEMIN = 1;
    static const unsigned int DISTANCEMAX = 2000;
};

std::ostream& operator<< (std::ostream& sortie, const Trajet& t);

std::istream& operator>> (std::istream& entree, Trajet& t);

#endif /* TRAJET_H */

