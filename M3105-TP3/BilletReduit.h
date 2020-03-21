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
    
    BilletReduit(const Client& client,const Trajet& trajet, const Tarif& tarif, const Promotion& unePromo);
    
    const Promotion& getPromotion() const;
    
    float getPrix() const override;
    
    void afficher(std::ostream& sortie = std::cout) const override;
    
private:
    const Promotion& promotion;
};

std::ostream& operator<< (std::ostream& sortie, const BilletReduit& b);

#endif /* BILLETREDUIT_H */

