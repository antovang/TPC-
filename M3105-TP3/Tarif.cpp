/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tarif.cpp
 * Author: vangriea
 * 
 * Created on March 18, 2020, 6:31 PM
 */

#include "Tarif.h"
using namespace std;

Tarif::Tarif(const string & unLibelle, float unPrixKilo):libelle(unLibelle),
prixAuKm(unPrixKilo,PRIXMIN,PRIXMAX){}

const string& Tarif::getLibelle() const{
    return this->libelle;
}

void Tarif::setLibelle(const string& libelle){
    this->libelle = libelle;
}

float Tarif::getPrixAuKm() const{
    return prixAuKm.getVal();
}

void Tarif::saisir(istream& entree){
    string libelle;
    
    entree >> libelle;
    
    setLibelle(libelle);   
}

void Tarif::afficher(ostream& sortie) const{
    sortie << getLibelle() << " (€" << getPrixAuKm() << " x Km)" << endl;
}

std::ostream& operator<< (std::ostream& sortie, const Tarif& t){
    t.afficher();
    return sortie;
}

std::istream& operator>> (std::istream& entree, Tarif& t){
    t.saisir();
    return entree;
}
