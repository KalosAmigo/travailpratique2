// TravailPratique2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Menu.h" //DONE
#include "Facture.h" //DONE
#include "Verification.h" //DONE


void ajouterDesNuits(Facture& _facture);
void ajouterDesRepas(Facture& _facture);
void ajouterAccesSpa(Facture& _facture);
void ajouterAccesGym(Facture& _facture);

int main() {
    Facture facture_test;
    bool sortir = false;

    do {
        int choix;
        Menu::afficherMenu();
        choix = Verification::verifierInt();

        switch (choix) {
        case 1:
            ajouterDesNuits(facture_test);
            break;
        case 2:
            ajouterDesRepas(facture_test);
            break;
        case 3:
            ajouterAccesSpa(facture_test);
            break;
        case 4:
            ajouterAccesGym(facture_test);
            break;
        case 5:
            sortir = true;
            facture_test.afficherFacture();      
            break;
        default:
            cout << "Choix non-valide. Reessayez." << endl;
        }
    } while (!sortir);
    return 0;
}

void ajouterDesNuits(Facture& _facture) {
    const double PRIX_NUIT = 100.00;
    int quantite;

    cout << "Combien de nuits a ajouter?: ";
    quantite = Verification::verifierInt();

    try {
        _facture.ajouterNuit(PRIX_NUIT, quantite);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
        cout << "Modification a la facture (nuits)." << endl;
        _facture.retirerNuit();
        _facture.ajouterNuit(PRIX_NUIT, quantite);
    }
}

void ajouterDesRepas(Facture& _facture) {
    const double PRIX_REPAS = 20.00;
    int quantite;

    cout << "Combien de repas a ajouter?: ";
    quantite = Verification::verifierInt();

    try {
        _facture.ajouterRepas(PRIX_REPAS, quantite);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
        cout << "Modification a la facture (repas)." << endl;
        _facture.retirerRepas();
        _facture.ajouterRepas(PRIX_REPAS, quantite);
    }
}

void ajouterAccesSpa(Facture& _facture) {
    const double PRIX_SPA = 75.00;

    try {
        _facture.ajouterSpa(PRIX_SPA);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void ajouterAccesGym(Facture& _facture) {
    const double PRIX_GYM = 50.00;

    try {
        _facture.ajouterGym(PRIX_GYM);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}