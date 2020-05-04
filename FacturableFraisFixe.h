#pragma once
#include "ElementFacturable.h"

class FacturableFraisFixe : public ElementFacturable {
private:
	const double TAXE_AJOUTEE = 1.07;
public:
	FacturableFraisFixe(string _nom, double _prix):ElementFacturable(_nom, _prix) {};
	~FacturableFraisFixe() {};
	double calculerTotalPlusTaxe() const { return (calculerTotal() * ((TAXE_BASE + TAXE_AJOUTEE) - 1)); };
};
