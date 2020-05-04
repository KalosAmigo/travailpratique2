#include "Verification.h"

const string Verification::INTEGER_NON_VALIDE = "Entree non-valide. La valeur entree n'est pas un chiffre entier.";

int Verification::verifierInt() {
    int integer;
    bool estValide = false;

    string lecture;
    cin >> lecture;

    do {
        try {
            integer = stoi(lecture); //Convert string to integer 
            estValide = true;
        }
        catch (invalid_argument) {
            cout << INTEGER_NON_VALIDE << endl;
        }
    } while (!estValide);

    return integer;
}

