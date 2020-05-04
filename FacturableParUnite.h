#pragma once
#include "ElementFacturable.h"

class FacturableParUnite : public ElementFacturable {
private:
	const double TAXE_HEBERGEMENT = 1.05;
	int quantite;

public:
	FacturableParUnite(string _nom, double _prix, int _quantite);
	~FacturableParUnite() {};
	void afficherElement() const;

	double calculerTotal() const { return prix * quantite; };
	double calculerTotalPlusTaxe() const { return (calculerTotal() * ((TAXE_HEBERGEMENT + TAXE_BASE) - 1)); }
};