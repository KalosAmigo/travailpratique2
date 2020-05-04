#include "Facture.h"

Facture::~Facture() {
    map<int, ElementFacturable*>::iterator ptr;

    for (ptr = map_elements.begin(); ptr != map_elements.end(); ptr++) {
        delete ptr->second;
        ptr->second = NULL; //Une chance on a stackoverflow
    } 
}

void Facture::ajouterNuit(double _prix, int _quantite) {
    const string NOM_NUIT = "Nuit";
    const int RANG = 1;

    if (_quantite < 0)
        throw invalid_argument("Erreur: La quantite est negative.");

    VerifierDuplique(RANG);

    FacturableParUnite* p_element = NULL;
    p_element = new FacturableParUnite(NOM_NUIT, _prix, _quantite);

    map_elements.insert(pair<int, ElementFacturable*>(RANG, p_element));
}


void Facture::ajouterRepas(double _prix, int _quantite) {
    const string NOM_REPAS = "Repas";
    const int RANG = 2;

    if (_quantite < 0)
        throw invalid_argument("Erreur: La quantite est negative.");

    VerifierDuplique(RANG);

    FacturableParUnite* p_element = NULL;
    p_element = new FacturableParUnite(NOM_REPAS, _prix, _quantite);

    map_elements.insert(pair<int, ElementFacturable*>(RANG, p_element));
}

void Facture::ajouterSpa(double _prix) {
    const string NOM_SPA = "Spa";
    const int RANG = 3;
    VerifierDuplique(RANG);

    FacturableFraisFixe* p_element = NULL;
    p_element = new FacturableFraisFixe(NOM_SPA, _prix);

    map_elements.insert(pair<int, ElementFacturable*>(RANG, p_element));
}

void Facture::ajouterGym(double _prix) {
    const string NOM_GYM = "Gym";
    const int RANG = 4;
    VerifierDuplique(RANG);

    FacturableFraisFixe* p_element = NULL;
    p_element = new FacturableFraisFixe(NOM_GYM, _prix);

    map_elements.insert(pair<int, ElementFacturable*>(RANG, p_element));
}

void Facture::afficherFacture() {
    double prix_total = 0;
    double prix_total_taxee = 0;

    cout << "    **     Facture     **    " << endl;

    if (map_elements.size() <= 0) {
        cout << "Aucun element dans la facture." << endl;
        return;
    }

    map<int, ElementFacturable*>::iterator ptr;
    for (ptr = map_elements.begin(); ptr != map_elements.end(); ptr++) {
        ptr->second->afficherElement();
        prix_total += ptr->second->calculerTotal();
        prix_total_taxee += ptr->second->calculerTotalPlusTaxe();
    }

    printf(" Sous-total: %10.2f $\n", prix_total);
    printf(" Taxes: %10.2f $\n", (prix_total_taxee - prix_total));
    printf(" Total Final: %10.2f $\n", prix_total_taxee);
}

void Facture::VerifierDuplique(int _rang) {
    if (map_elements.find(_rang) != map_elements.end()) {
        throw invalid_argument("Erreur: Element deja existant dans la facture.");
    }
}

void Facture::retirerNuit()
{
    map_elements.erase(1);
}

void Facture::retirerRepas()
{
    map_elements.erase(2);
}

void Facture::retirerSpa() {
    map_elements.erase(3);
}

void Facture::retirerGym() {
    map_elements.erase(4);
}