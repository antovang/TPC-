/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produit.cpp
 * Author: vangriea
 * 
 * Created on March 20, 2020, 7:10 PM
 */

#include "Produit.h"
using namespace std;

Produit::Produit(const Client& unClient):m_client(unClient){}

void Produit::ajouter(Produit& produit){
    throw "Impossible de rajouter un Produit";
}

const Client& Produit::getClient() const{
    return this->m_client;
}

ostream& operator<< (ostream& sortie, const Produit& p){
    p.afficher();
    return sortie;
}

