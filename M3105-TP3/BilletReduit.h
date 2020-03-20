/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BilletReduit.h
 * Author: vangriea
 *
 * Created on March 19, 2020, 5:15 PM
 */

#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H
#include "Promotion.h"
#include "Billet.h"
#include <iostream>

class BilletReduit : public Billet{
public:
    
    BilletReduit(Client& client,Trajet& trajet, Tarif& tarif, Promotion& unePromo);
    
    const Promotion& getPromotion() const;
    
    float getPrix() const override;
    
    void afficher(std::ostream& sortie = std::cout) const override;
    
private:
    const Promotion& promotion;
};

#endif /* BILLETREDUIT_H */

