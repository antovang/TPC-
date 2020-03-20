/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pack.h
 * Author: vangriea
 *
 * Created on March 20, 2020, 7:24 PM
 */

#ifndef PACK_H
#define PACK_H
#include <vector>
#include <string>
#include "Produit.h"
#include "Client.h"

class Pack : public Produit {
public:
    Pack(std::string& libelle, Client& client);
    
    const std::vector<Produit*> getContenu() const;
    
    virtual float getPrix() const override;
    
    void ajouter(Produit& produit) override;
    
private:
    std::string m_libelle;
    std::vector<Produit*> m_contenu;
};

#endif /* PACK_H */

