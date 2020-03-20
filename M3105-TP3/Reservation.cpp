/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reservation.cpp
 * Author: vangriea
 * 
 * Created on March 20, 2020, 7:10 PM
 */

#include "Reservation.h"
using namespace std;

const string Reservation::getNomHotel() const{
    return this->m_nomHotel;
}

int Reservation::getNbJours() const{
    return this->m_nbJours.getVal();
}

float Reservation::getPrixJour() const{
    return this->m_prixJour.getVal();
}

float Reservation::getPrix() const{
    return (getNbJours()*getPrixJour());
}

void Reservation::afficher(ostream& sortie) const{
    sortie << "Nombre de Jours : " << getNbJours() << endl 
            << "Prix Reservation : " << getPrix() << endl;
} 

ostream& operator<< (ostream& sortie, const Reservation& r){
    r.afficher();
    return sortie;
}