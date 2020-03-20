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
#include "Trajet.h"
#include "Tarif.h"
#include "Billet.h"
#include "BilletReduit.h"
#include "Promotion.h"
#include "Pack.h"
#include "Reservation.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Client unClient("Antonio","Van Grieken");
    Tarif unTarif("Tarif Générale",0.5);
    Trajet unTrajet("Lyon","Paris",467);
    Billet unBillet(unClient,unTrajet,unTarif);
    Promotion unePromo("Promo Anniversaire", 0.5);
    BilletReduit unBilletReduit(unClient,unTrajet,unTarif,unePromo);
    Reservation uneReservation("BestWestern",5,250.5,unClient);
    Pack unPack("Pack-Paris",unClient);
    
    unPack.ajouter(unBilletReduit);
    unPack.ajouter(uneReservation);
    
    unPack.afficher();
    
    return 0;
}

