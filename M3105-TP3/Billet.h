/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Billet.h
 * Author: vangriea
 *
 * Created on March 18, 2020, 7:59 PM
 */

#ifndef BILLET_H
#define BILLET_H
#include <iostream>
#include "Trajet.h"
#include "Tarif.h"
#include "Produit.h"
#include "Client.h"

class Billet : public Produit {
public:
    Billet(const Client& unClient, const Trajet& unTrajet, const Tarif& unTarif);
    
    const Trajet& getTrajet() const;
    
    const Tarif& getTarif() const;
    
    float getPrix() const override;
    
    void afficher(std::ostream& sortie = std::cout) const override;
    
private:
    const Trajet& trajet;
    const Tarif& tarif;
};

std::ostream& operator<< (std::ostream& sortie, const Billet& b);

#endif /* BILLET_H */

