/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.cpp
 * Author: vangriea
 * 
 * Created on March 19, 2020, 6:19 PM
 */

#include "Client.h"

Client::Client(const std::string& prenom, const std::string& nom):prenom(prenom),
    nom(nom){};

const std::string& Client::getPrenom() const{
    return this->prenom;
}

const std::string& Client::getNom() const{
    return this->nom;
}

