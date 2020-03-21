/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promotion.cpp
 * Author: vangriea
 * 
 * Created on March 18, 2020, 9:14 PM
 */

#include "Promotion.h"
using namespace std;

Promotion::Promotion(const string& unLibelle, float unTaux):libelle(unLibelle),
tauxReduction(unTaux,TAUXMIN,TAUXMAX){}

const string& Promotion::getLibelle() const{
    return this->libelle;
}

float Promotion::getTauxReduction() const {
    return this->tauxReduction.getVal() * 100;
}

void Promotion::setTaux(float taux){
    this->tauxReduction.setVal(taux);
}

void Promotion::setLibelle(const string& libelle){
    this->libelle = libelle;
}

float Promotion::calculPrixReduit(float prix) const{
    return (prix * tauxReduction.getVal());
}

void Promotion::saisir(istream& entree){
    string libelle;
    float taux;
    
    entree >> libelle >> taux;
    
    setLibelle(libelle);
    setTaux(taux);
}

void Promotion::afficher(ostream& sortie) const{
    sortie << getLibelle() << " <=> " << getTauxReduction() << "%" << endl;
}

ostream& operator<< (ostream& sortie, const Promotion& p){
    p.afficher();
    return sortie;
}
