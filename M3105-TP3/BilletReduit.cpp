/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BilletReduit.cpp
 * Author: vangriea
 * 
 * Created on March 19, 2020, 5:15 PM
 */

#include "BilletReduit.h"
#include "Billet.h"

BilletReduit::BilletReduit(Client& client, Trajet& trajet, Tarif& tarif, Promotion& unePromo):
Billet::Billet(client,trajet,tarif),promotion(unePromo){}

const Promotion& BilletReduit::getPromotion() const{
    return this->promotion;
}

float BilletReduit::getPrix() const{
    return getPromotion().calculPrixReduit(Billet::getPrix());
}

void BilletReduit::afficher(ostream& sortie) const{
    sortie  << "Billet : " << endl << getTrajet() << getTarif() << getPromotion() << "Total Prix s/Reduction : €" <<
        Billet::getPrix() << endl << "Total Prix Reduit : €" << getPrix() << endl;
}

ostream& operator<< (ostream& sortie, const BilletReduit& b){
    b.afficher();
    return sortie;
}

