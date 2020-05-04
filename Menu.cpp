#include <iostream>
#include "menu.h"

void Menu::afficherMenu() {
    cout << "        ** MENU **        " << endl << endl;
    cout << "  1. Ajouter des nuitees." << endl;
    cout << "  2. Ajouter des repas." << endl;
    cout << "  3. Ajouter un acces au spa." << endl;
    cout << "  4. Ajouter un acces au gym." << endl;
    cout << "  5. Afficher la facture et quitter." << endl;
    cout << endl << " Votre choix: ";
}