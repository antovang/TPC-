/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conteneur.cpp
 * Author: vangriea
 * 
 * Created on March 20, 2020, 10:36 PM
 */

#ifdef CONTENEUR_H

template <class T>
Conteneur<T>::Conteneur(){}

template <class T>
void Conteneur<T>::ajouter(const T& element){
    this->m_contenu.push_back(&element);
}

template <class T>
void Conteneur<T>::afficher(std::ostream & sortie) const{
    for (const T* elem : this->m_contenu) {
        sortie << " - " << *elem << endl;
    }
}

template <class T>
const T& Conteneur<T>::choisirElement(std::ostream& sortie, std::istream& entree){
    NombreContraint<int> n(1,1,m_contenu.size());
    bool ok;
    do {
        try {
            afficher();
            sortie << endl << "Votre choix : ";
            n.saisir(cin);
            ok = true;
            } catch (const char * e) {
            sortie << "Choix entre 1 et " << m_contenu.size() << endl;
            ok = false;
        }
    } while (!ok);
    return *this->m_contenu[n.getVal()-1];
}

#endif

