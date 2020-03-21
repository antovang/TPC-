/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.cpp
 * Author: vangriea
 * 
 * Created on March 19, 2020, 6:19 PM
 */

#include "Client.h"
using namespace std;

Client::Client(const std::string& prenom, const std::string& nom):prenom(prenom),
    nom(nom){};
    
void Client::setPrenom(const std::string& prenom){
    this->prenom = prenom;
}

void Client::setNom(const std::string& nom){
    this->nom = nom;
}

const std::string& Client::getPrenom() const{
    return this->prenom;
}

const std::string& Client::getNom() const{
    return this->nom;
}

void Client::saisir (std::ostream& sortie, std::istream& entree){
    std::string prenom;
    std::string nom;
    
    sortie << "Prenom : " ;
    entree >> prenom;
    sortie << " Nom : ";
    entree >> nom;
    
    setPrenom(prenom);
    setNom(nom);
}

void Client::afficher(ostream& sortie) const{
    sortie << getPrenom() << " " << getNom() << endl;
} 

ostream& operator<< (ostream& sortie, const Client& c){
    c.afficher();
    return sortie;
}
