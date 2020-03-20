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
    Pack(const std::string& libelle, Client& client);
    
    std::vector<const Produit*> getContenu() const;
    
    virtual float getPrix() const override;
    
    void ajouter(Produit& produit) override;
    
    void afficher(std::ostream& sortie = std::cout) const override;
    
private:
    std::string m_libelle;
    std::vector<const Produit*> m_contenu;
};

std::ostream& operator<< (std::ostream& sortie, const Pack& p);

#endif /* PACK_H */

