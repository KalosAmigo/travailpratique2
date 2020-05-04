#include "facturableParUnite.h"

FacturableParUnite::FacturableParUnite(string _nom, double _prix, int _quantite) : ElementFacturable(_nom, _prix) {
	if (_quantite < 0)
		throw invalid_argument("Erreur: La quantite est negative.");

	this->quantite = _quantite;
}

void FacturableParUnite::afficherElement() const {
	printf(" %-20s %8.2f $ %-3d \n", nom.c_str(), (prix * quantite), quantite);
}