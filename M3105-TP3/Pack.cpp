/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pack.cpp
 * Author: vangriea
 * 
 * Created on March 20, 2020, 7:24 PM
 */

#include "Pack.h"
using namespace std;

Pack::Pack(const string& libelle, Client& client):
    m_libelle(libelle),Produit::Produit(client){}

vector<const Produit*> Pack::getContenu() const{
    return this->m_contenu;
}

float Pack::getPrix() const{
    float m_prix = 0;
    
    for(const Produit* p : m_contenu){
        m_prix += p->getPrix();
    } 
    return m_prix;
}

void Pack::ajouter(Produit& produit){
    getContenu().push_back(&produit);
}

void Pack::afficher(ostream& sortie) const{
    sortie << getContenu().size() << endl;
}

ostream& operator<< (ostream& sortie, const Pack& p){
    p.afficher();
    return sortie;
}
