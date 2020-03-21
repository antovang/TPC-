/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Billet.cpp
 * Author: vangriea
 * 
 * Created on March 18, 2020, 7:59 PM
 */

#include "Billet.h"
using namespace std;

Billet::Billet(const Client& unClient,const Trajet& unTrajet, const Tarif& unTarif):
    Produit::Produit(unClient),trajet(unTrajet),tarif(unTarif){}

const Trajet& Billet::getTrajet() const{
    return this->trajet;
}

const Tarif& Billet::getTarif() const{
    return this->tarif;
}

float Billet::getPrix() const{
    return (this->trajet.getDistance() * this->tarif.getPrixAuKm());
}

void Billet::afficher(ostream& sortie) const{
    sortie  << "Client : " << Produit::getClient() << endl <<  getTrajet() << getTarif() << "Prix Total : €" << getPrix() << endl;
}

ostream& operator<< (ostream& sortie, const Billet& b){
    b.afficher();
    return sortie;
}
