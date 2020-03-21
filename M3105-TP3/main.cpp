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

void ajoutTrajet(Conteneur<Trajet>& conteneur){

    string villeDep;
    string villeArr;
    int dist;

    Trajet* trajet = new Trajet(villeDep,villeArr,dist);

    trajet->saisir();
    
    conteneur.ajouter(*trajet);
}


void ajoutTarif(Conteneur<Tarif>& conteneur){
    string libelle;
    float prixKilo;

    Tarif* tarif = new Tarif(libelle,prixKilo);

    tarif->saisir();
    
    conteneur.ajouter(*tarif);
}

void ajoutPromotion(Conteneur<Promotion>& conteneur){
    string libelle;
    float taux;

    Promotion* promotion = new Promotion(libelle,taux);

    promotion->saisir();
    
    conteneur.ajouter(*promotion);
}

void ajoutClient(Conteneur<Client>& conteneur){
    string prenom;
    string nom;

    Client* client = new Client(prenom,nom);

    client->saisir();
    
    conteneur.ajouter(*client);
}

void ajoutBillet(Conteneur<Tarif>& contTarif,Conteneur<Trajet>& contTrajet,
    Conteneur<Client>& contClient,Conteneur<Billet>& contBillet)
{
    const Tarif& tarif= contTarif.choisirElement();

    const Trajet& trajet= contTrajet.choisirElement();
    
    const Client& client= contClient.choisirElement();
    
    Billet* billet = new Billet(client,trajet,tarif);
    
    contBillet.ajouter(*billet);
}

void ajoutBilletReduit(Conteneur<Tarif>& contTarif,Conteneur<Trajet>& contTrajet,
    Conteneur<Client>& contClient, Conteneur<Promotion>& contPromo, Conteneur<BilletReduit>& contBilletReduit)
{
    const Tarif& tarif = contTarif.choisirElement();

    const Trajet& trajet = contTrajet.choisirElement();

    const Client& client = contClient.choisirElement();

    const Promotion& promo = contPromo.choisirElement();
    
    BilletReduit* billetR = new BilletReduit(client,trajet,tarif,promo);
    
    contBilletReduit.ajouter(*billetR);
}

int main(int argc, char** argv) {
    
    //Creation de conteneurs
    Conteneur<Tarif> conteneurTarif;
    Conteneur<Trajet> conteneurTrajet;
    Conteneur<Billet> conteneurBillet;
    Conteneur<BilletReduit> conteneurBilletReduit;
    Conteneur<Client> conteneurClient;
    Conteneur<Promotion> conteneurPromotion;
    
    //Creation de trajets,tarifs,promos
    Trajet* trajet = new Trajet("Merida","Caracas",758);
        conteneurTrajet.ajouter(*trajet);
    Tarif* tarif = new Tarif("TarifEtu",0.5);
        conteneurTarif.ajouter(*tarif);
    Client* client = new Client("Antonio","Van Grieken");
        conteneurClient.ajouter(*client);
    Promotion* promo = new Promotion("PromoEtu",0.5);
        conteneurPromotion.ajouter(*promo);
    
    bool sortir = false;
    
    cout << "Bienvenue !, Que voulez-vous faire ?" << endl << endl;
    
    do{

        cout  << "1. Créer des trajets" << endl
              << "2. Créer des tarifs" << endl
              << "3. Créer des promotions" << endl
              << "4. Créer des clients" << endl
              << "5. Créer un billet ou un billet réduit en choisissant ses « composants » "
                      "parmi les trajets/tarifs/clients/promotions déjà créés"  << endl 
              << "6. Sortir" << endl
              << "7. Voir les billets disponibles **sans réduction " << endl
              << "8. Voir les billets réduits disponibles " << endl;  

        NombreContraint<int> choix(6,1,8);
        NombreContraint<int> choixBR(1,1,2);
        
        cout << "Faites votre choix : ";
        choix.saisir();

        switch(choix.getVal()){
            case 1 :
                cout << "Entrez une ville de départ, une ville d'arrivée et une distance de trajet : ";
                ajoutTrajet(conteneurTrajet);
                break;
            case 2 :
                cout << "Entrez un libellé et un prix au kilomètre: ";
                ajoutTarif(conteneurTarif);
                break;
            case 3 :
                cout << "Entrez un libellé et un taux de réduction: ";
                ajoutPromotion(conteneurPromotion);
                break;
            case 4 :
                ajoutClient(conteneurClient);
                break;
            case 5 :
                cout << "Voulez vous créér un billet réduit (1 ou 2) ?" << endl << endl <<
                    "1. Oui" << endl <<
                    "2. Non" << endl;

                choixBR.saisir();
                if(choixBR.getVal() == 1){
                    ajoutBilletReduit(conteneurTarif,conteneurTrajet,conteneurClient,conteneurPromotion,conteneurBilletReduit);
                    break;
                }
                ajoutBillet(conteneurTarif,conteneurTrajet,conteneurClient,conteneurBillet);
                break;
            case 6 :
                sortir = true;
                break;
            case 7 :
                conteneurBillet.afficher();
                cout << endl << endl;
                break;
            case 8 :   
                conteneurBilletReduit.afficher();
                cout << endl << endl;
                break;
        }
    }while(sortir == false);
    
    return 0;
}

