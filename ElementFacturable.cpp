#include "ElementFacturable.h"

ElementFacturable::ElementFacturable(string _nom, double _prix) {
	if (_prix < 0)
		throw invalid_argument("Erreur: le prix est négatif.");

	this->nom = _nom;
	this->prix = _prix;
}


void ElementFacturable::afficherElement() const {
	printf(" %-20s %8.2f $ \n", nom.c_str(), prix);
}

