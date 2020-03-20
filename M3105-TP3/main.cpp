/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vangriea
 *
 * Created on March 18, 2020, 6:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "NombreContraint.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Billet.h"
#include "BilletReduit.h"
#include "Promotion.h"
#include "Pack.h"
#include "Reservation.h"
#include "Conteneur.h"

using namespace std;

/*
 * 
 */

void ajoutTrajet(){

    string villeDep;
    string villeArr;
    int dist;

    Trajet* trajet = new Trajet(villeDep,villeArr,dist);

    cout << "Entrez une ville de départ, une ville d'arrivée et une distance de trajet : ";
    trajet->saisir();
}


void ajoutTarif(){
    string libelle;
    float prixKilo;

    Tarif* tarif = new Tarif(libelle,prixKilo);

    cout << "Entrez un libellé et un prix au kilomètre: ";
    tarif->saisir();
}

void ajoutPromotion(){

}

void ajoutClient(){

}

void ajoutBilletReduit(){

}

int main(int argc, char** argv) {
    
    Conteneur<Tarif> conteneurTarif;
    Conteneur<Trajet> conteneurTrajet;
    Conteneur<Billet> conteneurBillet;
    Conteneur<BilletReduit> conteneurBilletReduit;
    Conteneur<Promotion> conteneurPromotion;
    
    cout << "Bienvenue !, Que voulez-vous faire ?" << endl << endl
         << "1. Créer des trajets" << endl
         << "2. Créer des tarifs" << endl
         << "3. Créer des promotions (NON DISPONIBLE)" << endl
         << "4. Créer des clients ((NON DISPONIBLE))" << endl
         << "5. Créer un billet ou un billet réduit en choisissant ses « composants » "
                "parmi les trajets/tarifs/clients/promotions déjà créés (NON DISPONIBLE)"  << endl;
    
    NombreContraint<int> choix(1,1,5);
    
    cout << "Faites votre choix : ";
    choix.saisir();
    
    switch(choix.getVal()){
        case 1 :
            ajoutTrajet();
        case 2 :
            ajoutTarif();
        case 3 : 
            ajoutPromotion();
        case 4 : 
            ajoutClient();
        case 5 :
            ajoutBilletReduit();
        default :
            cout << "Choix invalide";
    }
    
    return 0;
}

