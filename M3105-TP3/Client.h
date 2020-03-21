/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.h
 * Author: vangriea
 *
 * Created on March 19, 2020, 6:18 PM
 */

#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

class Client {
public:
    Client(const std::string& prenom, const std::string& nom);
    
    void setPrenom(const std::string& prenom);
    
    void setNom(const std::string& nom);
    
    const std::string& getPrenom() const;
    
    const std::string& getNom() const;
    
    void saisir(std::ostream& sortie = std::cout, std::istream& entree = std::cin);
    
    void afficher(std::ostream& sortie = std::cout) const;
    
private:
    std::string prenom;
    std::string nom;
};

std::ostream& operator<< (std::ostream& sortie, const Client& c);

#endif /* CLIENT_H */

