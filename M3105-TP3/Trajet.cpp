/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trajet.cpp
 * Author: vangriea
 * 
 * Created on March 18, 2020, 7:39 PM
 */

#include "Trajet.h"
using namespace std;

Trajet::Trajet(const string& villeDep,const string& villeArr,int dist):
villeDepart(villeDep), villeArrivee(villeArr), distance(dist,DISTANCEMIN,DISTANCEMAX){}

const string& Trajet::getVilleDep() const{
    return this->villeDepart;
}

void Trajet::setVilleDepart(const string& villeDep){
    this->villeDepart = villeDep;
}

const string& Trajet::getVilleArrivee() const{
    return this->villeArrivee;
}

void Trajet::setVilleArrivee(const string& villeArr){
    this->villeArrivee = villeArr;
}

int Trajet::getDistance() const{
    return this->distance.getVal();
}

void Trajet::setDistance(float dist){
    this->distance.setVal(dist);
}

void Trajet::saisir(istream& entree){
    string villeDep;
    string villeArr;
    float distance;
    
    entree >> villeDep >> villeArr >> distance;
    
    setVilleArrivee(villeArr);
    setVilleDepart(villeDep);
    setDistance(distance);
}

void Trajet::afficher(ostream& sortie) const{
    sortie << getVilleDep() << " -> " << getVilleArrivee() << " <=> " << getDistance() << "Km" << endl;
}

std::ostream& operator<< (std::ostream& sortie, const Trajet& t){
    t.afficher();
    return sortie;
}

std::istream& operator>> (std::istream& entree, Trajet& t){
    t.saisir();
    return entree;
}
