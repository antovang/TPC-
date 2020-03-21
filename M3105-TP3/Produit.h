/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produit.h
 * Author: vangriea
 *
 * Created on March 20, 2020, 7:10 PM
 */

#ifndef PRODUIT_H
#define PRODUIT_H
#include "Client.h"
#include <iostream>

class Produit {
public:
    Produit(const Client& unClient);
    
    virtual float getPrix() const=0;
    
    virtual void ajouter(Produit& produit);
    
    const Client& getClient() const;
    
    virtual void afficher(std::ostream& sortie = std::cout) const=0;
private:
    const Client& m_client;
};

std::ostream& operator<< (std::ostream& sortie, const Produit& p);

#endif /* PRODUIT_H */

