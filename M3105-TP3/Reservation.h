/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reservation.h
 * Author: vangriea
 *
 * Created on March 20, 2020, 7:10 PM
 */

#ifndef RESERVATION_H
#define RESERVATION_H
#include "Client.h"
#include <string>
#include "NombreContraint.h"
#include "Produit.h"

class Reservation : public Produit{
    
public:
    inline Reservation(const std::string nomHotel, int nbJours, float prixJour, Client& unClient):
    m_nomHotel(nomHotel),m_nbJours(nbJours),m_prixJour(prixJour), Produit(unClient){}

    const std::string getNomHotel() const;
    
    int getNbJours() const;
    
    float getPrixJour() const;
    
    float getPrix() const override;

    void afficher(std::ostream& sortie = std::cout) const override;
    
private:
    std::string m_nomHotel;
    NombreContraint<int> m_nbJours;
    NombreContraint<float> m_prixJour;
};

std::ostream& operator<< (std::ostream& sortie, const Reservation& r);

#endif /* RESERVATION_H */

